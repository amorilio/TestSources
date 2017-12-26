// Printer.cpp: implementation of the Printer class.
//
//////////////////////////////////////////////////////////////////////

#include "Printer.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int Printer::numOfObjects = 0;

Printer* Printer::instance()
{
	if (numOfObjects > maxObjects)
		throw TooManyObjects();

	++numOfObjects;
	return new Printer();
}

Printer::~Printer()
{
	--numOfObjects;
}

Printer* Printer::instance(const Printer& p)
{
	if (numOfObjects > maxObjects)
		throw TooManyObjects();
	++numOfObjects;

	return new Printer(p);
}