// QuickFind.h: interface for the QuickFind class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_QUICKFIND_H__5F047D16_2E21_45D5_84AC_94F1A8649811__INCLUDED_)
#define AFX_QUICKFIND_H__5F047D16_2E21_45D5_84AC_94F1A8649811__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class QuickFind
{
public:
	QuickFind();
	virtual ~QuickFind();

	void Print(int array[]);
	void Connect(int p, int q);
	bool IsConnect(int p, int q);
};

#endif // !defined(AFX_QUICKFIND_H__5F047D16_2E21_45D5_84AC_94F1A8649811__INCLUDED_)
