// Adapter.h: interface for the Adapter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADAPTER_H__009F07BC_4B03_488A_8DB4_54A48EF1AC20__INCLUDED_)
#define AFX_ADAPTER_H__009F07BC_4B03_488A_8DB4_54A48EF1AC20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// The old: three totally incompatible classes no common base class,
class A {
public:
	~A();
	void doThis();
};

class B {
public:
	~B();
	void doThat();
};

class C {
public:
	~C();
	void doTheOther();
};

class NewInterface
{
public:
	NewInterface() {};
	virtual ~NewInterface() {};
	virtual void execute() = 0;
};

template <class T>
class ExternalPolymorphismAdapter : public NewInterface
{
public:
	ExternalPolymorphismAdapter(T* object, void(T::*method)());
	virtual ~ExternalPolymorphismAdapter();
	void execute();

private:
	T* _object;				// ptr-to-object attribute
    void(T::*_method)();	// ptr-to-member-function attribute
};

extern void ExternalPolymorphismAdapterTest();

class Old
{
public:
	Old(int a, int b, int c);
	void doStuff();
};

class Adapter : public NewInterface, private Old
{
public:
	Adapter(int x);
	void execute();
};

extern void AdapterTest();

#endif // !defined(AFX_ADAPTER_H__009F07BC_4B03_488A_8DB4_54A48EF1AC20__INCLUDED_)
