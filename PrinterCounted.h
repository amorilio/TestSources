// PrinterCounted.h: interface for the PrinterCounted class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTERCOUNTED_H__970B2151_787D_4690_BBE6_BF65691C9495__INCLUDED_)
#define AFX_PRINTERCOUNTED_H__970B2151_787D_4690_BBE6_BF65691C9495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ObjectsCounter.h"

class PrinterCounted : public Counted<PrinterCounted>
{
public:
	static PrinterCounted* instance();
	static PrinterCounted* instance(const PrinterCounted& p);

	~PrinterCounted() {};

	using Counted<PrinterCounted>::objectsCount;
	using Counted<PrinterCounted>::TooManyObjects;

private:
	PrinterCounted() {};
	PrinterCounted(const PrinterCounted&) {};
	

};

#endif // !defined(AFX_PRINTERCOUNTED_H__970B2151_787D_4690_BBE6_BF65691C9495__INCLUDED_)
