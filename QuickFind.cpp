// QuickFind.cpp: implementation of the QuickFind class.
//
//////////////////////////////////////////////////////////////////////

#include "QuickFind.h"
#include <IOSTREAM>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define iArraySize 10
int id[iArraySize];

QuickFind::QuickFind()
{
	for (int i=0; i < iArraySize; i++)
	{
		id[i] = i;
	}
	Print(id);
	//9-1 8-0 3-0 3-4 7-8 4-6
	Connect(8,0);
	Connect(3,0);
	Connect(3,4);
	Connect(7,8);
	Connect(4,6);
	Print(id);
}

void QuickFind::Connect(int p, int q)
{
	for(int i=0; i<iArraySize; i++)
		if(id[i] == id[p])
			id[i] = id[q];
}

void QuickFind::Print(int array[])
{
	for(int i=0; i < iArraySize; i++)
		cout<<array[i]<<" ";
	cout<<endl;
}

bool QuickFind::IsConnect(int p, int q)
{
	return id[p] == id[q];
}

QuickFind::~QuickFind()
{
}