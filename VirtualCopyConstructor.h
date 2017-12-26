// VirtualCopyConstructor.h: interface for the VirtualCopyConstructor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIRTUALCOPYCONSTRUCTOR_H__3C848F2C_36D2_426D_AC64_8C4F5DB66981__INCLUDED_)
#define AFX_VIRTUALCOPYCONSTRUCTOR_H__3C848F2C_36D2_426D_AC64_8C4F5DB66981__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
using namespace std;

class VirtualCopyConstructor
{
public:
    VirtualCopyConstructor();

	// Ensures to invoke actual object destructor
    virtual ~VirtualCopyConstructor();

    virtual void ChangeAttributes() = 0;

    // The "Virtual Constructor"
    static VirtualCopyConstructor *Create(int id);

    // The "Virtual Copy Constructor"
    virtual VirtualCopyConstructor *Clone() = 0;
};

class Derived1 : public VirtualCopyConstructor
{
public:
    Derived1()						{        cout << "Derived1 created" << endl;    }
    Derived1(const Derived1& rhs)   {        cout << "Derived1 created by deep copy" << endl;    }
    ~Derived1()						{        cout << "~Derived1 destroyed" << endl;    }
    void ChangeAttributes()			{        cout << "Derived1 Attributes Changed" << endl;    }
    VirtualCopyConstructor *Clone() {        return new Derived1(*this);    }
};

class Derived2 : public VirtualCopyConstructor
{
public:
    Derived2()						{        cout << "Derived2 created" << endl;    }
    Derived2(const Derived2& rhs)   {       cout << "Derived2 created by deep copy" << endl;    }
    ~Derived2()						{        cout << "~Derived2 destroyed" << endl;    }
    void ChangeAttributes()			{        cout << "Derived2 Attributes Changed" << endl;    }
    VirtualCopyConstructor *Clone() {        return new Derived2(*this);    }
};

class Derived3 : public VirtualCopyConstructor
{
public:
    Derived3()						{        cout << "Derived3 created" << endl;    }
    Derived3(const Derived3& rhs)   {        cout << "Derived3 created by deep copy" << endl;    }
    ~Derived3()						{        cout << "~Derived3 destroyed" << endl;    }
    void ChangeAttributes()			{        cout << "Derived3 Attributes Changed" << endl;    }
    VirtualCopyConstructor *Clone() {        return new Derived3(*this);    }
};
//// LIBRARY END

//// UTILITY SRART
class User
{
public:
    User() : pVirtualCopyConstructor(0)
    {
        // Creates any object of VirtualCopyConstructor heirarchey at runtime

        int input = 3;

        //cout << "Enter ID (1, 2 or 3): ";
        //cin >> input;


        while( (input !=  1) && (input !=  2) && (input !=  3) )
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }

        // Create objects via the "Virtual Constructor"
        pVirtualCopyConstructor = VirtualCopyConstructor::Create(input);
    }

    ~User()
    {
        if( pVirtualCopyConstructor )
        {
            delete pVirtualCopyConstructor;
            pVirtualCopyConstructor = 0;
        }
    }

    void Action()
    {
        // Duplicate current object
        VirtualCopyConstructor *pNewVirtualCopyConstructor = pVirtualCopyConstructor->Clone();

        // Change its attributes
        pNewVirtualCopyConstructor->ChangeAttributes();

        // Dispose the created object
        delete pNewVirtualCopyConstructor;
    }

private:
    VirtualCopyConstructor *pVirtualCopyConstructor;
};

#endif // !defined(AFX_VIRTUALCOPYCONSTRUCTOR_H__3C848F2C_36D2_426D_AC64_8C4F5DB66981__INCLUDED_)
