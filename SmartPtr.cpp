// SmartPtr.cpp: implementation of the SmartPtr class.
//
//////////////////////////////////////////////////////////////////////

#include "SmartPtr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template <class T>
void SmartPtr<T>::init()
{
	if (pointee)
		addReference();
}

template <class T>
SmartPtr<T>::SmartPtr(T* realPtr) : pointee(realPtr)
{
	init();
}

template <class T>
SmartPtr<T>::SmartPtr(SmartPtr<T>& sptr)
{
	pointee = sptr.pointee;
	init();
}

template <class T>
SmartPtr<T>::~SmartPtr()
{
	removeReference();
}

template <class T>
SmartPtr<T>& SmartPtr<T>::operator=(SmartPtr& sptr)
{
	if (pointee != sptr.pointee)
	{
		T* oldPointee = pointee;
		pointee = sptr.pointee;
		init();
		if(oldPointee)
			sptr.removeReference();
	}
	return *this;
}
template <class T>
T& SmartPtr<T>::operator*()  const
{
	return &pointee;
}

template <class T>
T* SmartPtr<T>::operator->() const
{
	return pointee;
}

class Test //: public ReferenceCounter
{
public:
	Test() : i(5) {};
	Test(int i) : i(i) {};
	virtual ~Test() {};
	int		getI() {return i;}
	void	setI(int input) {i = input;}
private:
	int i;
};

#include <iostream>
using namespace std;
void testSmartPtr()
{
	SmartPtr<Test> testSptr1 = new Test(7);
	SmartPtr<Test> testSptr2 = new Test(9);
	cout << "testSptr1 = "<<testSptr1->getI()<<" testSptr2 = "<<testSptr2->getI()<< endl;

	SmartPtr<Test> testSptr3(testSptr1);
	SmartPtr<Test> testSptr4;
	testSptr4 = testSptr2;
	cout << "testSptr3 = "<<testSptr3->getI()<<" testSptr4 = "<<testSptr4->getI()<< endl;

	testSptr3->setI(10);
	testSptr4->setI(20);
	cout << "testSptr3 = "<<testSptr3->getI()<<" testSptr4 = "<<testSptr4->getI()<< endl;
}