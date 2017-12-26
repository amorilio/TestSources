// Composite.cpp: implementation of the Composite class.
//
//////////////////////////////////////////////////////////////////////

#include "Composite.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "math.h"

void ClientComposite()
{
	Composite* c1 = new Composite(1);
	Composite* c2 = new Composite(2);
	Simple *s1	  = new Simple(11);
	Simple *s2	  = new Simple(22);
	c1->addChild(c2);
	c1->addChild(s1);
	c1->addChild(s2);
	Composite* c3 = new Composite(2);
	Simple *s3	  = new Simple(33);
	Simple *s4	  = new Simple(44);
	c2->addChild(c3);
	c2->addChild(s3);
	c2->addChild(s4);
	Simple *s5	  = new Simple(55);
	Simple *s6	  = new Simple(66);
	c3->addChild(s5);
	c3->addChild(s6);

	c1->print();
}