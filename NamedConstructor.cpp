// NamedConstructor.cpp: implementation of the NamedConstructor class.
//
//////////////////////////////////////////////////////////////////////

#include "NamedConstructor.h"

#include <cmath>

//using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// INLINE CONSTRUCTOR
inline NamedConstructor::NamedConstructor(float x, float y): x_(x), y_(y)
{ }

// INLINE NAMED CONSTRUCTORS (Same parameters , different functionality)
inline NamedConstructor NamedConstructor::rectangular(float x, float y)
{
	return NamedConstructor(x, y);
}

inline NamedConstructor NamedConstructor::polar(float radius, float angle)
{
	return NamedConstructor(radius*(float)cos(angle), radius*(float)sin(angle));
}

void NamedConstructorTest()
{
	NamedConstructor p1 = NamedConstructor::rectangular((float)5.7, (float)1.2);   // Obviously rectangular
	NamedConstructor p2 = NamedConstructor::polar((float)5.7, (float)1.2);         // Obviously polar
}