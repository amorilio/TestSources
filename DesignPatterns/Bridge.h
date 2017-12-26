// Bridge.h: interface for the Bridge class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRIDGE_H__99699853_65A0_4D68_8B23_F809189C814E__INCLUDED_)
#define AFX_BRIDGE_H__99699853_65A0_4D68_8B23_F809189C814E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Bridge
{
public:
	Bridge();
	virtual ~Bridge();
};

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class TimeImp {
public:
    TimeImp(int hr, int min);
	virtual ~TimeImp() {}
    virtual void tell();
protected:
    int hr_, min_;
};

class CivilianTimeImp: public TimeImp {
public:
    CivilianTimeImp(int hr, int min, int pm);
    void tell();
protected:
    char whichM_[4];
};

class ZuluTimeImp: public TimeImp {
public:
    ZuluTimeImp(int hr, int min, int zone);
    void tell();
protected:
    char zone_[30];
};

class Time {
public:
    Time() {};
    Time(int hr, int min);
	virtual ~Time() {}
    virtual void tell();
protected:
    TimeImp *imp_;
};

class CivilianTime: public Time {
public:
    CivilianTime(int hr, int min, int pm);
};

class ZuluTime: public Time {
public:
    ZuluTime(int hr, int min, int zone);
};

#endif // !defined(AFX_BRIDGE_H__99699853_65A0_4D68_8B23_F809189C814E__INCLUDED_)
