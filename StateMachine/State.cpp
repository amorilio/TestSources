#include "State.h"

using namespace std;

//************************************
// Class:     State
// Access:    abstract public 
//
// State class is an abstract base class for States Hierarchy.
// - It manages vector of expected events sequence
// - It manages iterator over expected events sequence. This iterator incremented by State_Processing and reseted by State_Idle
// - holds completed message to be print if we hit State_Found
//************************************

void State::printSequence()
{
	cout<<"Sequence is: ";
	for(std::vector<CharacterEvent>::iterator it = m_sequence.begin(); it != m_sequence.end(); ++it)
	{
		cout<<(*it).getValue();
	}
	cout<<endl;
}

vector<CharacterEvent> State::getPassedEvents()
{
	if(m_currentEvent != m_sequence.begin())
		return vector<CharacterEvent> ( m_sequence.begin(), m_currentEvent+1 ) ;
	else
		return vector<CharacterEvent> ( m_sequence.begin(), m_currentEvent ) ;
}

//************************************
// Class:     State_Idle
// Access:    public 
//
// This class derived from State Class.
// State_Processing state activated at Initialization of state machine 
// or In case that we received unexpected Event in in state Processing
// or In as a result of State_Found handleEvent function.
//
// handleEvent of state State_Idle has 2 possible options.
// 1. we received event indicating start of sequence - Move to State_Processing 
// 2. any other event - stay in mode State_Idle
//************************************

State* State_Idle::handleEvent(CharacterEvent& e)
{
	if ( ((*m_currentEvent).getValue() == e.getValue())		|| 
		 ((*m_currentEvent).getValue() == AnyEvent::AnyEventChar) )
	{
		return new State_Processing(m_sequence, m_sCompletionMessage);
	}
	else 
	{
		return this;
	}
};

void State_Idle::printSequence()
{
	cout<<"State_Idle ";
	State::printSequence();
}

//************************************
// Class:     State_Processing
// Access:    public 
//
// This class derived from State Class.
// State_Processing state activated when at least one event 
// from required event sequences arrived. 
//
// handleEvent of state State_Processing has 3 possible options.
//	1. if we received last event from required sequence (m_currentEvent+1 == m_sequence.end()) 
//		create State_Found state and call it's handle event logic.
//  2. if we received expected value which is not end of required sequence return THIS
//	3. If we received unexpected Event , Switch to State_Idle and call it's handleEvent.
//************************************
State* State_Processing::handleEvent(CharacterEvent& e)
{
	m_currentEvent++;

	//
	//	in case that received expected event or AnyEvent , and it's end of sequence --> move to State_Found
	//
	if ((m_currentEvent+1) == m_sequence.end() && 
		(	((*m_currentEvent).getValue() == e.getValue())		|| 
			((*m_currentEvent).getValue() == AnyEvent::AnyEventChar) )	)
	{
		State* foundState = new State_Found(m_sequence, m_sCompletionMessage);	
		State* newState = foundState->handleEvent(e);
		if(newState != foundState)
			delete foundState;
		return newState;
	}


	//
	//	in case that received expected event or AnyEvent , and it's not end of sequence --> stay in State_Processing
	//
	if (((*m_currentEvent).getValue() == e.getValue())		|| 
		((*m_currentEvent).getValue() == AnyEvent::AnyEventChar) )
	{
		return this;
	}

	//
	//	in case that received unexpected event --> move to State_Idle
	//
	State* idleState = new State_Idle(m_sequence, m_sCompletionMessage);	
	State* newState = idleState->handleEvent(e);
	if(newState != idleState)
		delete idleState;
	return newState;
};

void State_Processing::printSequence()
{
	cout<<"State_Processing ";
	State::printSequence();
}

//************************************
// Class:     State_Found
// Access:    public 
//
// This class derived from State Class.
// State_Found state activated if required pattern supplied by user.
// handleEvent - function of State_Found prints relevant message and 
// switches the to Idle State.
//************************************

State* State_Found::handleEvent(CharacterEvent& e)
{
	//For Debugging [12/6/2015 imanasherov]
	//cout<<"--- Switched to state --->State_Found : "<< m_sCompletionMessage <<endl;
	cout<< m_sCompletionMessage << endl;
	return new State_Idle(m_sequence, m_sCompletionMessage);
};

void State_Found::printSequence()
{
	cout<<"State_Found ";
	State::printSequence();
}
