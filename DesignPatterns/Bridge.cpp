// Bridge.cpp: implementation of the Bridge class.
//
//////////////////////////////////////////////////////////////////////
#pragma warning(disable: 4996)
#include "Bridge.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Bridge::Bridge()
{
	Time *times[3];
	times[0] = new Time(14, 30);
	times[1] = new CivilianTime(2, 30, 1);
	times[2] = new ZuluTime(14, 30, 6);
	for (int i = 0; i < 3; i++)
    times[i]->tell();
}

Bridge::~Bridge()
{
}

TimeImp::TimeImp(int hr, int min)
{
	hr_ = hr;
	min_ = min;
}

void TimeImp::tell()
{
	std::cout << "time is " <<  hr_ << ":"<< min_ <<endl;
}

CivilianTimeImp::CivilianTimeImp(int hr, int min, int pm): TimeImp(hr, min)
{
	if (pm)
		strcpy(whichM_, " PM");
	else
		strcpy(whichM_, " AM");
}

void CivilianTimeImp::tell()
{
	cout << "time is " << hr_ << ":" << min_ << whichM_ << endl;
}

ZuluTimeImp::ZuluTimeImp(int hr, int min, int zone): TimeImp(hr, min)
{
	if (zone == 5)
		strcpy(zone_, " Eastern Standard Time");
	else if (zone == 6)
		strcpy(zone_, " Central Standard Time");
}

void ZuluTimeImp::tell()
{
	cout << "time is " << hr_ << ":"<< min_ << zone_ <<endl;
}

Time::Time(int hr, int min)
{
	imp_ = new TimeImp(hr, min);
}
void Time::tell()
{
	imp_->tell();
}

CivilianTime::CivilianTime(int hr, int min, int pm)
{
	imp_ = new CivilianTimeImp(hr, min, pm);
};

ZuluTime::ZuluTime(int hr, int min, int zone)
{
    imp_ = new ZuluTimeImp(hr, min, zone);
}