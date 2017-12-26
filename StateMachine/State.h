#pragma once

#include "Event.h"
#include <vector>

class State
{
public:
	virtual ~State() { };	

	virtual State* handleEvent(CharacterEvent& e)	= 0;
	virtual std::string name()						= 0;
	virtual void printSequence()					= 0;
	
	std::vector<CharacterEvent> getPassedEvents();

protected:	
	State( std::vector<CharacterEvent> eventsSequence, std::string message): 
		 m_sequence(eventsSequence) , 
		 m_currentEvent(m_sequence.begin()) , 
		 m_sCompletionMessage(message) { };
	State( const State& s): 
		m_sequence(s.m_sequence), 
		m_currentEvent(s.m_currentEvent) , 
		m_sCompletionMessage(s.m_sCompletionMessage) { };

	std::vector<CharacterEvent>				m_sequence;
	std::vector<CharacterEvent>::iterator	m_currentEvent;
	std::string								m_sCompletionMessage;
};

class State_Idle : public State
{
public:
	State_Idle(std::vector<CharacterEvent> eventsSequence, std::string message)
		: State(eventsSequence, message) { }
	State_Idle( const State_Idle& s) : State(s) { };
	virtual ~State_Idle() { };

	State* handleEvent(CharacterEvent& e);
	virtual std::string name() {return "State_Idle"; };
	virtual void printSequence(); 
};

class State_Processing : public State
{
public:	
	State_Processing(std::vector<CharacterEvent> eventsSequence, std::string message)
		: State(eventsSequence, message) { }
	State_Processing( const State_Processing& s) : State(s) { };
	virtual ~State_Processing(void) { };

	State* handleEvent(CharacterEvent& e);
	virtual std::string name() {return "State_Processing"; };
	virtual void printSequence();
};

class State_Found : public State
{
public:
	State_Found(std::vector<CharacterEvent> eventsSequence, std::string message)
		: State(eventsSequence, message) {};
	State_Found( const State_Found& s) : State(s) { };
	virtual ~State_Found(void) { };

	State* handleEvent(CharacterEvent& e);
	virtual std::string name() {return "State_Found"; };
	virtual void printSequence();
};


