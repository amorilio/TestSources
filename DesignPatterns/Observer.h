// Observer.h: interface for the Observer class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_OBSERVER_H__9087A675_C736_41B1_8AE7_CEAA21EC127F__INCLUDED_)
#define AFX_OBSERVER_H__9087A675_C736_41B1_8AE7_CEAA21EC127F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include <memory>

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void Update() = 0;
};

class MyObserver1 : public Observer
{
public:
	virtual ~MyObserver1()
	{
	}

	virtual void Update();
};

class MyObserver2 : public Observer
{
public:
	virtual ~MyObserver2()
	{
	}

	virtual void Update();
};

class Observable
{
public:
	explicit Observable(){};

	virtual ~Observable(){};

	void attachObserver(std::shared_ptr<Observer> o);

	void detachObserver(std::shared_ptr<Observer> o);

	void do_staff();

private:
	std::vector<std::shared_ptr< Observer >> m_observersList;
};

extern void observerTest();

#endif // !defined(AFX_OBSERVER_H__9087A675_C736_41B1_8AE7_CEAA21EC127F__INCLUDED_)
