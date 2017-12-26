// Singleton.cpp: implementation of the Singleton class.
//
//////////////////////////////////////////////////////////////////////

#include "Singleton.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Singleton* Singleton::instance_ = 0;
CRITICAL_SECTION _Mutex_Singleton;

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

Singleton* Singleton::instance()
{
	EnterCriticalSection (&_Mutex_Singleton);
	if (instance_ == 0)
		instance_ = new Singleton();
	LeaveCriticalSection (&_Mutex_Singleton);
	return instance_;
}

template<class T>
T& SingletonTemplate<T>::GetInstance()
{
	EnterCriticalSection (&_Mutex_Singleton);
	static T instance;
	LeaveCriticalSection (&_Mutex_Singleton);
	return instance;
}

void ClientSingleton()
{
	InitializeCriticalSection (&_Mutex_Singleton);
	Singleton* obj1 = Singleton::instance();
	obj1->func();
	Singleton* obj2 = Singleton::instance();
	obj2->func();

	int obj3 = SingletonTemplate<int>::GetInstance();
	obj3 = 5;
	int obj4 = SingletonTemplate<int>::GetInstance();
	obj4 = 8;
}