#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <sys/timeb.h>
#include "time.h"
#include <conio.h>

#include <iostream>
#include "Graph.h"
#include "IPConverter.h"
using namespace std;

#pragma warning (disable : 4996)

void GetOngoingTime(char *pFullTime)
{
	struct timeb xTimeb;
	::ftime(&xTimeb);
	time_t nSeconds = xTimeb.time;
	char cBuffer[1000];
	int nMilliSec = xTimeb.millitm;

	time_t xTime_t;
	struct tm * pTimeinfo;
	time (&xTime_t);
	pTimeinfo = localtime(&xTime_t);
	strftime(pFullTime,60,"%H:%M:%S:",pTimeinfo);
	sprintf(cBuffer, "%03d", nMilliSec);

	strcat(pFullTime, cBuffer);
	strcat(pFullTime, " ");
}

#include "SingleLinkList.h"
#include "InheritanceTest.h"
#include "NamedConstructor.h"
#include "BinaryTree.h"
#include "StringAlgoritms.h"
#include "NumberAlgorithms.h"
#include "QuickFind.h"
#include "VirtualCopyConstructor.h"
#include "Threads.h"

#include "Printer.h"
#include "SmartPtr.h"
#include "BigNumber.h"
#include "Stack.h"
#include "DoubleLinkList.h"

#include "BitMagic.h"
#include "LRUCache.h"
#include "HashMap.h"
#include "RedBlackTree.h"
#include "ReadWriteMutex.h"

#include<iostream>
using namespace std;

void fun(const int &i)
{
	cout << "fun(const int &) called ";
}
void fun(int &i)
{
	cout << "fun(int &) called " ;
}

#include <iomanip>
#include <sstream>

void printTest()
{
	int		iNumOfColumns = 3;
	int		intArr[50];
	double	doubleArr[50];
	string  stringArr[50];

	for (int i = 0; i < 50; i++)
	{
		intArr[i]		= 10;
		doubleArr[i]	= 15.5;
		stringArr[i]	= "Ilia";
	}

	stringstream ssRow;
	int colWidth = 24;
	ssRow<<setfill('#')<<setw(iNumOfColumns*colWidth)<<"#"<<endl;

	for(int i = 0; i < iNumOfColumns; i++)
	{
		stringstream ssTitle;
		ssTitle<<"Column "<<i;
		ssRow<<std::left<<setfill(' ')<<setw(colWidth-1)<<ssTitle.str();
	}
	ssRow<<endl;
	ssRow<<setfill('#')<<setw(iNumOfColumns*colWidth)<<"#"<<endl;
	for(int row = 0; row < 50; row++)
	{
		ssRow<<std::left<<setfill(' ')<<setw(colWidth-1)<<intArr[row];
		ssRow<<std::left<<setfill(' ')<<setw(colWidth-1)<<doubleArr[row];
		ssRow<<std::left<<setfill(' ')<<setw(colWidth-1)<<stringArr[row];
		ssRow<<endl;
	}
	ssRow<<setfill('#')<<setw(iNumOfColumns*colWidth)<<"#"<<endl;
	cout<<ssRow.str();
};

class A
{
public :
	virtual void f() {cout <<"do f"<<endl;}
};
class B : public A
{
public :
	virtual void f() {cout <<"do B"<<endl;}
};

void main()
{

	testIPConverter();

	ReadWriteMutexTest();

	RedBlackTreeTest();

	heap_test();

	GraphTest();

	TestLRUCache();

	BitMagic b;

	printTest();

	DoubleLinkList dList;
	dList.unitTest();

	BigNumberTest();

	const int i = 10;
	fun(i);

	//testSmartPtr();

	StackTest();

	try
	{
		Printer* p1 = Printer::instance();
		Printer* p2 = Printer::instance();
		Printer* p3 = Printer::instance(*p2);
		Printer* p4 = Printer::instance(*p2);
	} catch (Printer::TooManyObjects e)
	{
		printf("%s", e.what());
	}

	Threads threadTest;

	//VirtualCopyConstructor
	User *user = new User();
	user->Action();
	delete user;

	QuickFind			qf;
	StringAlgoritms		stringAlgo;
	NumberAlgorithms	numberAlgo;
	SingleLinkList		list;

	NamedConstructorTest();
	InheritanceTest();

	//	Tree				tree;
	BinaryTree		bTree;
	_getch();
}