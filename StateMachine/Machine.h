#pragma once

#include "State.h"
#include <vector>

class Machine
{
public:
	Machine(void);
	virtual ~Machine(void);

	void handleEvent(CharacterEvent& e);

	void generateConfigFile();
	void populateSequencesFromConfig();

	void dumpStatesImage();
	void readStatesImage();

private:
	void handleStateEvent(int iSequenceIndex, CharacterEvent& e);
	void Reset();

	static const char DumpChar	= 'd';
	static const char ResetChar = 'r';

	std::vector< State * >						m_vSequenceStates;
	std::vector< std::vector<CharacterEvent> >	m_vEventSequences;
};

