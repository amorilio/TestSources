// AbstracteFactory.cpp: implementation of the AbstracteFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "AbstracteFactory.h"

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void ClientAbstractFactory(int wos)
{
	AbstractFactory*		factory = NULL;
	AbstractThreadLayer*	threads = NULL;
	AbstractFileLayer*		file	= NULL;

	if (wos == AbstractFactory::WorkingOperatingSystem::WINDOWS)
	{
		factory = new WindowsFactory();
		threads = factory->createThreadLayer();
		file = factory->createFileLayer();
	}
	else if (wos == AbstractFactory::WorkingOperatingSystem::LINUX)
	{
		factory = new LinuxFactory();
		threads = factory->createThreadLayer();
		file = factory->createFileLayer();
	}
	else
	{
		std::cout<< "Unknown Operating System required"<<endl;
		return;
	}

	threads->create();
	threads->join();

	file->open();
	file->close();
	return;
}