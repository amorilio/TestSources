// Singleton.h: interface for the Singleton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLETON_H__1ED716AD_D389_4BD8_9813_47EF4EA9988F__INCLUDED_)
#define AFX_SINGLETON_H__1ED716AD_D389_4BD8_9813_47EF4EA9988F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>

class Singleton
{
public:
	static Singleton* instance();

	void func() {std::cout<<"Dummy Singleton func() called on object: "<< this <<std::endl;}

protected:
	Singleton();
	virtual ~Singleton();

	static Singleton* instance_;
};

extern void ClientSingleton();

#include "windows.h"
#include <cassert>

template<class T>
class SingletonTemplate
{
public:
	static T& GetInstance();
private:
	SingletonTemplate() {}
	~SingletonTemplate() {}
};

#endif // !defined(AFX_SINGLETON_H__1ED716AD_D389_4BD8_9813_47EF4EA9988F__INCLUDED_)