#include <iostream>
#include "Observer.h"
using namespace std;

#include "Singleton.h"
#include "Prototype.h"
#include "AbstracteFactory.h"
#include "Composite.h"
#include "Bridge.h"
#include "Adapter.h"
#include "Decorator.h"
#include "InnerBuilder.h"
#include "FactoryMethod.h"

extern int WidgetContainerTest();

void main()
{
    cout<<"Design Patterns Test Package start"<<endl;

    cout<<"--------------Singleton--------------"<<endl;
    ClientSingleton();
    cout<<"--------------Singleton--------------"<<endl;

    cout<<"--------------Prototype--------------"<<endl;
    ClientPrototype();
    cout<<"--------------Prototype--------------"<<endl;

    cout<<"--------------AbstractFactory--------------"<<endl;
    ClientAbstractFactory(AbstractFactory::WorkingOperatingSystem::WINDOWS);
    ClientAbstractFactory(AbstractFactory::WorkingOperatingSystem::LINUX);
    cout<<"--------------AbstractFactory--------------"<<endl;

    cout<<"--------------Composite--------------"<<endl;
    ClientComposite();
    cout<<"--------------Composite--------------"<<endl;

    cout<<"--------------Bridge--------------"<<endl;
    Bridge();
    cout<<"--------------Bridge--------------"<<endl;

    cout<<"--------------Adapter--------------"<<endl;
    AdapterTest();
    ExternalPolymorphismAdapterTest();
    cout<<"--------------Adapter--------------"<<endl;

    cout << "--------------Decorator--------------" << endl;
    DecoratorTest();
    cout << "--------------Decorator--------------" << endl;

    cout << "--------------Observer--------------" << endl;
    observerTest();
	cout << "--------------Observer--------------" << endl;

	cout << "--------------Inner Builder--------------" << endl;
	InnerBuilderTest();
	cout << "--------------Inner Builder--------------" << endl;

	cout << "--------------Factory Method Test--------------" << endl;
	FactoryMethodTest();
	cout << "--------------Factory Method Test--------------" << endl;

	cout << "--------------WidgetContainerTest --------------" << endl;
	WidgetContainerTest();
	cout << "--------------WidgetContainerTest--------------" << endl;

}