// Decorator.h: interface for the Decorator class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DECORATOR_H__395562D8_0CC6_4784_B10D_F8CD738629D0__INCLUDED_)
#define AFX_DECORATOR_H__395562D8_0CC6_4784_B10D_F8CD738629D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std;

class BaseComponent
{
public:
    virtual void doAction() = 0;
};

class ConcreateComponent : public BaseComponent
{
public:
    virtual void doAction();
};

class BaseDecorator : public BaseComponent
{
protected:
    BaseComponent *m_bComponent;
public:
    BaseDecorator(BaseComponent *bComponent) : m_bComponent(bComponent) {}
    virtual ~BaseDecorator() {}
    virtual void setBaseComponent(BaseComponent *bComponent)    = 0;
    virtual void doAction()                                     = 0;
};

class ConcreteDecoratorA : public BaseDecorator
{
public:
    ConcreteDecoratorA(BaseComponent *bComponent);
    virtual ~ConcreteDecoratorA();
    void setBaseComponent(BaseComponent *bComponent);
    void doAction();
};

class ConcreteDecoratorB : public BaseDecorator
{
public:
    ConcreteDecoratorB(BaseComponent *bComponent);
    virtual ~ConcreteDecoratorB();
    void setBaseComponent(BaseComponent *bComponent);
    void doAction();

};


void DecoratorTest();

#endif // !defined(AFX_DECORATOR_H__395562D8_0CC6_4784_B10D_F8CD738629D0__INCLUDED_)
