// Observer.cpp: implementation of the Observer class.
//
//////////////////////////////////////////////////////////////////////

#include "Observer.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Observer::Observer()
{
}

Observer::~Observer()
{
}

void MyObserver1::Update()
{
	std::cout << "MyObserver1 Updated." << std::endl;
}

void MyObserver2::Update()
{
	std::cout << "MyObserver2 Updated." << std::endl;
}

void Observable::attachObserver(std::shared_ptr<Observer> o)
{
	m_observersList.push_back(o);
}

void Observable::detachObserver(std::shared_ptr<Observer> o)
{
	std::vector<std::shared_ptr<Observer>>::iterator it = std::find(m_observersList.begin(), m_observersList.end(), o);
	if (it != m_observersList.end())
		m_observersList.erase(it);
}

void Observable::do_staff()
{
	/* do some interesting stuff , threads statuses ... etc */
	for (std::shared_ptr<Observer> o : m_observersList)
	{
		o->Update();
	}
}

void observerTest()
{
	Observable* theObject = new Observable();

	std::shared_ptr<MyObserver1> mo1(new MyObserver1());
	std::shared_ptr<MyObserver2> mo2(new MyObserver2());

	theObject->attachObserver(mo1);
	theObject->attachObserver(mo2);

	theObject->do_staff();

	theObject->detachObserver(mo1);
	theObject->detachObserver(mo2);

	theObject->do_staff();
}
