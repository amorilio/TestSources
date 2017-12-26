// NamedConstructor.h: interface for the NamedConstructor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NAMEDCONSTRUCTOR_H__4DADCEDA_336B_49D8_9869_B1C4409A1A24__INCLUDED_)
#define AFX_NAMEDCONSTRUCTOR_H__4DADCEDA_336B_49D8_9869_B1C4409A1A24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class NamedConstructor
{
public:
	// These static methods are the so-called "named constructors"
	static NamedConstructor rectangular(float x, float y);      // Rectangular coordinates
	static NamedConstructor polar(float radius, float angle);   // Polar			coordinates

private:
	NamedConstructor(float x, float y);									// Rectangular coordinates
	float x_, y_;
};

void NamedConstructorTest();

#endif // !defined(AFX_NAMEDCONSTRUCTOR_H__4DADCEDA_336B_49D8_9869_B1C4409A1A24__INCLUDED_)
