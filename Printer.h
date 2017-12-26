// Printer.h: interface for the Printer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRINTER_H__71AFE880_66A5_4AA6_B0E3_33D34E32521A__INCLUDED_)
#define AFX_PRINTER_H__71AFE880_66A5_4AA6_B0E3_33D34E32521A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Printer
{
public:
	class TooManyObjects
	{
	public:
		char* what() { return "Too Many Objects Created";}
	};

	virtual ~Printer();

	static Printer* instance();
	static Printer* instance(const Printer& p);

private:
	static int numOfObjects;
	//static const int maxObjects = 10;
	enum {maxObjects = 2};

	Printer() {};
	Printer(const Printer& p) {};
};

#endif // !defined(AFX_PRINTER_H__71AFE880_66A5_4AA6_B0E3_33D34E32521A__INCLUDED_)
