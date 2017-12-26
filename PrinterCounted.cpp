// PrinterCounted.cpp: implementation of the PrinterCounted class.
//
//////////////////////////////////////////////////////////////////////

#include "PrinterCounted.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int Counted<PrinterCounted>::maxNumOfObjects = 10;
int Counted<PrinterCounted>::numOfObjects = 0;

PrinterCounted* PrinterCounted::instance()
{
	return new PrinterCounted();
}

PrinterCounted* PrinterCounted::instance(const PrinterCounted& p)
{	
	return new PrinterCounted(p);
}
