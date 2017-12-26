// InheritanceTest.cpp: implementation of the InheritanceTest class.
//
//////////////////////////////////////////////////////////////////////

#include "InheritanceTest.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Base::Base() : m_private(1),m_protected(2),m_public(3)
										{	cout<<"Base::Base Called"<<endl;	}
Base::~Base()						{	cout<<"Base::~Base Called"<<endl;	}
void Base::foo()					{	cout<<"Base::foo Called"<<endl;	}
void Base::fooPublic()			{	cout<<"Base::fooPublic Called"<<endl;	}
void Base::fooProtected()		{	cout<<"Base::fooProtected Called"<<endl;	}
void Base::fooPrivate()			{	cout<<"Base::fooPrivate Called"<<endl;	}

Derivated1::Derivated1()		{	cout<<"Derivated1::Derivated1 Called"<<endl;	}
Derivated1::~Derivated1()		{	cout<<"Derivated1::~Derivated1 Called"<<endl;	}
void Derivated1::foo()			{	cout<<"Derivated1::foo Called"<<endl;	}
void Derivated1::foo1()			{	cout<<"Derivated1::foo1 Called"<<endl;	}
void Derivated1::fooPublic()	{	cout<<"Derivated1::fooVirt Called"<<endl;	}

Derivated2::Derivated2()		{	cout<<"Derivated2::Derivated1 Called"<<endl;	}
Derivated2::~Derivated2()		{	cout<<"Derivated2::~Derivated1 Called"<<endl;	}
void Derivated2::foo()			{	cout<<"Derivated2::foo Called"<<endl;	}
void Derivated2::foo1()			{	cout<<"Derivated2::foo1 Called"<<endl;	}
void Derivated2::fooPublic()	{	cout<<"Derivated2::fooVirt Called"<<endl;	}

class A
{
public:
	A() { cout<<"A"<<endl; }
};

class B
{
public:
	B() { cout<<"B"<<endl; }
};

class C
{
public:
	C() { cout<<"C"<<endl; }
};

class D
{
public:
	D() { cout<<"D"<<endl; }
};

class E : public D
{
public:
	E(C& c) : c(c) { cout<<"E"<<endl; }

	A	a;
	B*	b;
	C&	c;
};

void InheritanceTest()
{
	// First Initialize Base Class (Data Members -> Constructor)
	// Initialize data members
	//		Not Pointer
	//		Not Reference - must be passed in initialization list.
	// Call Constructor
	C c;
	E e(c);

	cout<<"-----new b1----->"<<endl;
	Base* b1			= new Base();
	cout<<"-----new b2----->"<<endl;
	Base* b2			= new Derivated1();
	//Base* b3			= new Derivated2();	<<<--- ERROR error C2243: 'type cast' : conversion from 'class Derivated2 *' to 'class Base *' exists, but is inaccessible
	cout<<"-----new d2----->"<<endl;
	Derivated1* d1 = new Derivated1();
	Derivated2* d2 = new Derivated2();
	// Derivated1* d2 = new Base();		<<<--- ERROR cannot convert from 'class Base *' to 'class Derivated1 *'

	cout<<"-----test b1----->"<<endl;
	b1->foo();
	b1->fooPublic();

	cout<<"-----test b2----->"<<endl;
	b2->foo();
	b2->fooPublic();

	cout<<"-----test d1----->"<<endl;
	d1->foo();
	d1->fooPublic();

	cout<<"-----test d2----->"<<endl;
	d2->foo();
	d2->fooPublic();

	cout<<"-----delete b1----->"<<endl;
	delete b1;
	cout<<"-----delete b2----->"<<endl;
	delete b2;
	cout<<"-----delete d1----->"<<endl;
	delete d1;
	delete d2;

	SisterClassDelegationTest();
	SizesTest();
}

void SisterDer1::foo()	{ bar(); }
void SisterDer2::bar()	{ cout<<"SisterDer2::bar is Called"<<endl; }
void SisterClassDelegationTest()
{
	SisterJoin* p1 = new SisterJoin();
	SisterDer1* p2 = p1;
	SisterBase* p3 = p1;

	cout<<"-------------------SisterClassDelegationTest-------------------"<<endl;
	p1->foo();
	p2->foo();
	p3->foo();
	cout<<"-------------------SisterClassDelegationTest-------------------"<<endl;
}

class Empty {};
class Derived1 : public Empty {};
class Derived2 : virtual public Empty {};
class Derived3 : public Empty
{
	char c;
};
class Derived4 : virtual public Empty
{
	char c;
};
class Dummy
{
	char c;
};

void SizesTest()
{
	cout<<"-------------------SizesTest-------------------"<<endl;
	cout << "sizeof(Empty) " << sizeof(Empty) << endl;
	cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
	cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
	cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
	cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
	cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
	cout<<"-------------------SizesTest-------------------"<<endl;
}