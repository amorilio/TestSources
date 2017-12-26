#include "Event.h"
#include "State.h"
#include "Machine.h"

using namespace std;
void main()
{	
	cout << "-------------- Starting State Machine -------------- "<<endl;
	cout << "Character Events (a,b or c other events will be ignored):"<<endl;
	cout << "Enter 'd' to create current image dump file"<<endl;
	cout << "Enter 'r' to reset all states to IDLE"<<endl;
	cout << "Enter 'q' to quit"<<endl<<endl;
	Machine m;
	while(1)
	{
		cout << "Enter Event --> ";
		string input;
		getline(cin, input);

		if(!string("q").compare(input))
			break;

		if(input.length() != 1 || !isalpha(input[0]))
			cout << "Only valid events are single character events.\n";
		else
		{
			char c = input[0];
			CharacterEvent e(c);
			m.handleEvent(e);
		}
	}

	cout << "Thanks and goodbye. \n";
}