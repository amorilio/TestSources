// Adapter.cpp: implementation of the Adapter class.
//
//////////////////////////////////////////////////////////////////////

#include "Adapter.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;

A::~A()
{
    cout << "A::dtor" << endl;
};

void A::doThis()
{
    cout << "A::doThis()" << endl;
};

B::~B()
{
    cout << "B::dtor" << endl;
};

void B::doThat()
{
   cout << "B::doThat()" << endl;
};

C::~C()
{
    cout << "C::dtor" << endl;
};

void C::doTheOther()
{
    cout << "C::doTheOther()" << endl;
};

template <class T>
ExternalPolymorphismAdapter<T>::ExternalPolymorphismAdapter(T* object, void(T::*method)()) :
    _object(object), _method(method)
{
};

template <class T>
ExternalPolymorphismAdapter<T>::~ExternalPolymorphismAdapter() {
    delete _object;
};

template <class T>
void ExternalPolymorphismAdapter<T>::execute() {
    (_object->*_method)();
}

void ExternalPolymorphismAdapterTest()
{
    cout<<"--------- Start ExternalPolymorphismAdapterTest ---------"<<endl;
    NewInterface ** objects = new NewInterface *[3];
    objects[0] = new ExternalPolymorphismAdapter<A> (new A, &A::doThis);
    objects[1] = new ExternalPolymorphismAdapter<B> (new B, &B::doThat);
    objects[2] = new ExternalPolymorphismAdapter<C> (new C, &C::doTheOther);

    for ( int i = 0; i < 3; i++)
    {
        objects[i]->execute();
        delete objects[i];
    }
    delete objects;
}

Old::Old(int a, int b, int c)
{
    cout<<"Old Constructor"<<endl;
};
void Old::doStuff()
{
    cout<<"Old Do Stuff" << endl;
};

Adapter::Adapter(int x) : Old(x,x,x)
{
    cout<<"Adapter Constructor"<<endl;
};

void Adapter::execute()
{
    cout<<"Adapter execute"<<endl;
    doStuff();
};

void AdapterTest()
{
    cout<<"--------- Start AdapterTest ---------"<<endl;
    Adapter a(10);
    a.execute();
}