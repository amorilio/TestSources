#include "FactoryMethod.h"
#include <string>
#include <iostream>

using namespace std;


//
//	Option 1: static factory method makeDocument
//
Document* Document::makeDocument(char choice)
{
	switch (choice)
	{
	case 'a': return new DocumentA(); break;
	case 'b': return new DocumentB(); break;
	default: return NULL;
	}
}

//
//	Option 2: Document factory class. If Document constructors are private , DocumentFactory should be friend.
//
Document* DocumentFactory::makeDocument(char choice)
{
	switch (choice)
	{
	case 'a': return new DocumentA; break;
	case 'b': return new DocumentB; break;
	default: return NULL;
	}
}

//
//	Option 3: NewDocument will call concrete CreateDocument metod of overloaded classes.
//
Document* Application::NewDocument()
{
	_docs[_index] = CreateDocument();
	_docs[_index]->open();
	return _docs[_index++];
}
Document* ApplicationA::CreateDocument()	{ return new DocumentA(); }
Document* ApplicationB::CreateDocument()	{ return new DocumentB(); }

void FactoryMethodTest()
{
	int i = 0;
	//1. Static Factory Method
	std::cout << "10 Ramdomy Generated Objects	- Static Factory Method" << std::endl;
	Document *_docs[30];
	for (i = 0; i < 10; i++)
	{		
		_docs[i] = rand() % 2 ? Document::makeDocument('a') : Document::makeDocument('b');
	}

	for (i = 0; i < 10; i++)		std::cout << _docs[i]->getName() << endl;

	//2. Factory Class
	std::cout << "10 Ramdomy Generated Objects	- Factory Class" << std::endl;
	DocumentFactory* f = new DocumentFactory();
	for (i = 10; i < 20; i++)
	{
		_docs[i] = rand() % 2 ? f->makeDocument('a') : f->makeDocument('b');
	}
	for (i = 10; i < 20; i++)		std::cout << _docs[i]->getName() << endl;

	//3. Application specific Document Factory
	ApplicationA appA;
	std::cout << "5 DocumentA objects generated with concreate ApplicationA Class" << std::endl;
	for (i = 20; i < 25; i++)
	{
		_docs[i] = appA.NewDocument();
	}
	for (i = 20; i < 25; i++) std::cout << _docs[i]->getName() << endl;
	ApplicationB appB;
	std::cout << "5 DocumentA objects generated with concreate ApplicationB Class" << std::endl;
	for (i = 25; i < 30; i++)
	{
		_docs[i] = appB.NewDocument();
	}
	for (i = 25; i < 30; i++) std::cout << _docs[i]->getName() << endl;
}