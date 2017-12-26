// Threads.h: interface for the Threads class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THREADS_H__7637D9C8_01A0_4417_8701_A2A42BDF38FE__INCLUDED_)
#define AFX_THREADS_H__7637D9C8_01A0_4417_8701_A2A42BDF38FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <windows.h>
#include <stdio.h>

#define MAX_SEM_COUNT 10
#define THREADCOUNT 12

class Threads
{
public:
	Threads();
	virtual ~Threads();
};

#endif // !defined(AFX_THREADS_H__7637D9C8_01A0_4417_8701_A2A42BDF38FE__INCLUDED_)
