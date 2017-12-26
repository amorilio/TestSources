// VirtualCopyConstructor.cpp: implementation of the VirtualCopyConstructor class.
//
//////////////////////////////////////////////////////////////////////

#include "VirtualCopyConstructor.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

VirtualCopyConstructor::VirtualCopyConstructor()
{
}

VirtualCopyConstructor::~VirtualCopyConstructor()
{
}

// We can also declare "Create" outside VirtualCopyConstructor.
// But is more relevant to limit it's scope to VirtualCopyConstructor
VirtualCopyConstructor *VirtualCopyConstructor::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User need not be recompiled to create newly added class objects

    if( id == 1 )
    {
        return new Derived1;
    }
    else if( id == 2 )
    {
        return new Derived2;
    }
    else
    {
        return new Derived3;
    }
}