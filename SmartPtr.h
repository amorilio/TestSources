// SmartPtr.h: interface for the SmartPtr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMARTPTR_H__64605754_781F_4CC6_B322_E0233422A395__INCLUDED_)
#define AFX_SMARTPTR_H__64605754_781F_4CC6_B322_E0233422A395__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern void testSmartPtr();

class ReferenceCounter
{
public:
	void addReference()		{++referenceCount;};
	void removeReference()	{--referenceCount; if (referenceCount == 0) delete this;};
	int  isShared()			{return (referenceCount > 1);};
protected:
	virtual ~ReferenceCounter() = 0								      {};
	ReferenceCounter()						   : referenceCount(0)	{};
	ReferenceCounter(ReferenceCounter& r)	: referenceCount(0)	{};
	const ReferenceCounter& operator=(ReferenceCounter& r)		{return *this;};
private:
	int referenceCount;
};

template<class T>
class SmartPtr : public ReferenceCounter
{
public:
	SmartPtr(T* ptr=0) ;
	SmartPtr(SmartPtr& sptr);
	SmartPtr& operator=(SmartPtr& sptr);
	virtual ~SmartPtr();

	T& operator*()  const;
	T* operator->() const;

private:
	void init();

	T* pointee;
};

#endif // !defined(AFX_SMARTPTR_H__64605754_781F_4CC6_B322_E0233422A395__INCLUDED_)
