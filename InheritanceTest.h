// InheritanceTest.h: interface for the InheritanceTest class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INHERITANCETEST_H__9D0025D6_46ED_42C2_97DB_FFD4D1F304E7__INCLUDED_)
#define AFX_INHERITANCETEST_H__9D0025D6_46ED_42C2_97DB_FFD4D1F304E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Base
{
public:
	Base();
	~Base();
	void foo();

	virtual void fooPublic();
	int m_public;
protected:
	virtual void fooProtected();
	int m_protected;
private:
	virtual void fooPrivate();
	int m_private;
};

class Derivated1 : public Base
{
public:
	Derivated1();
	~Derivated1();
	void foo();
	void foo1();
	void fooPublic();
};

class Derivated2 : private  Base
{
public:
	Derivated2();
	~Derivated2();
	void foo();
	void foo1();
	void fooPublic();
};

void InheritanceTest();

#pragma warning(disable : 4250)

class SisterBase {
public:
	virtual void foo() = 0;
	virtual void bar() = 0;
};

class SisterDer1 : public virtual SisterBase {
public:
	virtual void foo();	// Has no BAR function , but SisterDer2::bar will called.
};

class SisterDer2 : public virtual SisterBase {
public:
	virtual void bar();
};

class SisterJoin : public SisterDer1, public SisterDer2 {
public:
};

void SisterClassDelegationTest();
void SizesTest();

#endif // !defined(AFX_INHERITANCETEST_H__9D0025D6_46ED_42C2_97DB_FFD4D1F304E7__INCLUDED_)
