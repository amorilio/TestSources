#include "Machine.h"
#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define CONFIG_FILE "config.txt"
#define IMAGE_FILE	"statesImage.txt"

//************************************
// Method:    dumpStatesImage
// FullName:  Machine::dumpStatesImage
//
// flush each one of current sequence states into the IMAGE_FILE
// IMAGE_FILE is been parsed in constructor of Machine.
//************************************
void Machine::dumpStatesImage()
{
    remove( IMAGE_FILE );

    ofstream myfile(IMAGE_FILE);
    if (!myfile.is_open())
    {
        cout<<"ERROR: can not open "<<IMAGE_FILE<< " for writing"<<endl;
        return;
    }

    int iNumOfSequences = m_vSequenceStates.size();
    for(int sq = 0; sq < iNumOfSequences; sq++)
    {
        if(m_vSequenceStates[sq])
        {
            vector<CharacterEvent> passedEvents = m_vSequenceStates[sq]->getPassedEvents();
            if (passedEvents.empty())
            {				
                myfile <<"IDLE"<< endl;
                continue;
            }
            for(vector<CharacterEvent>::iterator it = passedEvents.begin(); it < passedEvents.end(); ++it)
            {
                myfile << (*it).getValue();
            }
            myfile << endl;
        }
    }
    myfile.close();	
    cout<<"Current States Image successfully dumped to: "<<IMAGE_FILE<<endl;
}

//************************************
// Method:    readStatesImage
// FullName:  Machine::readStatesImage
//
// Reads states from previous run if they were dumped using 'd' command
//************************************
void Machine::readStatesImage()
{
    string line;
    ifstream myfile (IMAGE_FILE);
    if (!myfile.is_open())
    {
        cout<<"Warning: can not open "<<IMAGE_FILE<< " for reading"<<endl;
        return;
    }
    
    int iSequenceIndex = 0;
    while ( getline (myfile,line) )
    {		
        if(!std::string("IDLE").compare(line))
            continue;

        if(m_vSequenceStates[iSequenceIndex])
        {
            for(string::iterator it = line.begin(); it < line.end(); ++it)
            {
                CharacterEvent e(*it);
                handleStateEvent(iSequenceIndex, e);
            }
        }
        iSequenceIndex++;
    }
}

//************************************
// Method:    generateConfigFile
// FullName:  Machine::generateConfigFile
// 
// Generates CONFIG_FILE and populates it by default event sequences.
//************************************
void Machine::generateConfigFile()
{
    if (std::ifstream(CONFIG_FILE))
    {
        return;
    }

    std::cout << CONFIG_FILE<<" not founds. Generating default configuration file for testing." << std::endl;

    ofstream myfile(CONFIG_FILE);
    if (!myfile)
    {
         std::cout << CONFIG_FILE<<" File could not be created" << std::endl;
         return;
    }

    myfile << "aabca\n";
    myfile << "ab";
    for (int i = 0; i < 1000; i++)
        myfile << "c";
    myfile << "a\n";
    myfile << "ac*\n";

    myfile.close();
}

//************************************
// Method:    populateSequencesFromConfig
// FullName:  Machine::populateSequencesFromConfig
//
// Parse CONFIG_FILE read configured sequences from it and populate 
//************************************
void Machine::populateSequencesFromConfig()
{
    m_vEventSequences.clear();

    string line;
    ifstream myfile (CONFIG_FILE);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            vector<CharacterEvent> sequence;
            sequence.clear();

            for (std::string::iterator it = line.begin(), end = line.end(); it != end; ++it)
            {
                if(*it == AnyEvent::AnyEventChar)
                {
                    AnyEvent anyEvent;
                    sequence.push_back(anyEvent);

                } else {
                    CharacterEvent characterEvent(*it);
                    sequence.push_back(characterEvent);
                }
            }
            m_vEventSequences.push_back(sequence);
        }
        myfile.close();
    }
}

//************************************
// Method:    Reset
// FullName:  Machine::Reset
// 
// Utility funciton which cleans Machine::states vector and re-popultates if by Idle states for each one of sequence.
//************************************
void Machine::Reset()
{	
    cout << "Reseting Event Sequence states." << endl;

    int iNumOfSates = m_vSequenceStates.size();
    for(int i = 0; i < iNumOfSates; i++)
        delete m_vSequenceStates[i];
    m_vSequenceStates.clear();

    int iNumOfSequences = m_vEventSequences.size();
    for(int iSequenceIndex = 0; iSequenceIndex < iNumOfSequences; iSequenceIndex++)
    {
        stringstream ss;
        ss<<"Seq "<<iSequenceIndex+1;
        m_vSequenceStates.push_back ( new State_Idle(m_vEventSequences[iSequenceIndex], ss.str()) );
    }
}

//************************************
// Method:    Machine
// FullName:  Machine::Machine
// 
// Constructor of State Machine. 
//
// The list of required Event sequences supplied to State machine from CONFIG_FILE file.
// If config file not exists State machine calls generateConfigFile function which generates config file with some default event sequences. 
//	Later, CONFIG_FILE file may be manually updated by user if some other/additional sequences will be needed.
//
// State machine reads sequences from CONFIG_FILE, and populates event sequences vector Machine::sequences
//
// Reset function is responsible of populating sequences STATES vector Machine::states by Idle state per each one of event sequence.
//
// Once sequences STATES vector Machine::states is populated by default Idle states we call readStatesImage function which checks 
//	if we have some "dump" file from previous run and switch each one of states to proper state.
//
//************************************
Machine::Machine()
{
    cout<<"----------- State Machine Initialization ----------- "<<endl;
    cout<<"----------- Retrieve Known Sequences from "<<CONFIG_FILE<<" ----------- "<<endl;

    // generate default sequences configuration file if not exists.
    generateConfigFile();

    // Populate Machine::sequences vector by sequences retrieved from configuration file 
    populateSequencesFromConfig();
    
    cout<<"----------- Prepare States ----------- "<<endl<<endl;
    // reset all sequence states to State_Idle	
    Reset();

    cout<<"----------- Known Sequences ----------- "<<endl<<endl;
    // Printout configured Sequences and states.
    int iNumOfStates = m_vSequenceStates.size();
    for(int iStateIndex = 0; iStateIndex < iNumOfStates; iStateIndex++)
    {
        m_vSequenceStates[iStateIndex]->printSequence();
    }
    
    cout<<"----------- Reload States from "<<IMAGE_FILE<<" ----------- "<<endl<<endl;
    // Read States Image if exists
    readStatesImage();

    cout<<"----------- Finish Machine Initialization ----------- "<<endl<<endl;
}

Machine::~Machine()
{
}

//************************************
// Method:    handleStateEvent
// FullName:  Machine::handleStateEvent
//
// Delegate received event to sequence state. 
// If returned state differs from current state - update Sequence states vector.
//************************************
void Machine::handleStateEvent(int iSequenceIndex, CharacterEvent& e)
{
    State* newState = m_vSequenceStates[iSequenceIndex]->handleEvent(e);
    if(newState != m_vSequenceStates[iSequenceIndex])
    {
        delete m_vSequenceStates[iSequenceIndex];
        m_vSequenceStates[iSequenceIndex] = newState;
        //For Debugging [12/6/2015 imanasherov]
        //cout<<"--- Switched to state --->"<<states[iSequenceIndex]->name()<<endl;
    }
}

//************************************
// Method:    handleEvent
// FullName:  Machine::handleEvent
//
// check if received 'd' - Dump current states to image or 'r' - reset states reserved commands 
//
// if case that received any other event relegate it to each one of sequence states from Machine::states vector
//************************************
void Machine::handleEvent(CharacterEvent& e)
{
    if(e.getValue() == DumpChar)
    {
        return dumpStatesImage();
    }
    if(e.getValue() == ResetChar)
    {
        return Reset();
    }

    int iNumOfSequences = m_vSequenceStates.size();
    for(int iSequenceIndex = 0; iSequenceIndex < iNumOfSequences; iSequenceIndex++)
    {
        if(m_vSequenceStates[iSequenceIndex])
        {
            handleStateEvent(iSequenceIndex, e);
        }
    }
}