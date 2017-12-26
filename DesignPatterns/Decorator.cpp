// Decorator.cpp: implementation of the Decorator class.
//
//////////////////////////////////////////////////////////////////////

#include "Decorator.h"

void ConcreateComponent::doAction() { 
    cout << "ConcreateComponent doAction" << endl; 
}

ConcreteDecoratorA::ConcreteDecoratorA(BaseComponent *bComponent) : BaseDecorator(bComponent){}
ConcreteDecoratorA::~ConcreteDecoratorA(){}
void ConcreteDecoratorA::setBaseComponent(BaseComponent *bComponent) {     m_bComponent = bComponent; }
void ConcreteDecoratorA::doAction() 
{ 
    m_bComponent->doAction();
    cout << "ConcreteDecoratorA doAction" << endl;
}

ConcreteDecoratorB::ConcreteDecoratorB(BaseComponent *bComponent) : BaseDecorator(bComponent){}
ConcreteDecoratorB::~ConcreteDecoratorB(){}
void ConcreteDecoratorB::setBaseComponent(BaseComponent *bComponent) {     m_bComponent = bComponent; }
void ConcreteDecoratorB::doAction() { 
    m_bComponent->doAction();
    cout << "ConcreteDecoratorB doAction" << endl;
}

void DecoratorTest()
{
    BaseComponent* component1 = new ConcreteDecoratorA(new ConcreateComponent());
    cout << "-----------------Component 1 Action-----------------" << endl;
    component1->doAction();
    BaseComponent* component2 = new ConcreteDecoratorA(new ConcreteDecoratorB(new ConcreateComponent()));
    cout << "-----------------Component 2 Action-----------------" << endl;
    component2->doAction();
}
