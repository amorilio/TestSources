// Rand.cpp: implementation of the Rand class.
//
//////////////////////////////////////////////////////////////////////

#include "Rand.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Rand::Rand()
{
}

Rand::~Rand()
{
}

#pragma warning (disable : 4786)

#include <iostream>
#include <iomanip>
#include "math.h"
#include <algorithm>
#include "time.h"
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef pair<string,int> MyElement;
#define NUM_OF_ITERATIONS 1000

int compare_qsort (const void * a, const void * b)
{
	cout<<"Comparing: "<<((MyElement *)a)->first<<" : "<<((MyElement *)b)->first<<endl;
	return ((MyElement *)a)->second > ((MyElement *)b)->second;
}

int compare_sort (const MyElement& a, const MyElement&  b)
{
	return a.second > b.second;
}

int main(int argc, char* argv[])
{
	int i = 0;

	vector<MyElement>	vecOfData;

	for(i = 1; i < argc; i++)
	{
		vecOfData.push_back(MyElement(argv[i], 0));
	}

	i = NUM_OF_ITERATIONS;
    srand(time(0));
	while ( i-- )
	{
		vecOfData[ (rand() % (argc-1)) ].second++;
	}

	/*
	cout<< "Results Before Sorting:"<<endl;
	for(i = 0; i < argc-1; i++)
	{
		cout<<setiosflags(ios::left)  <<setw(10)<< vecOfData[i].first << " , count: " << vecOfData[i].second << endl;
	}
	*/
	//qsort(&vecOfData, vecOfData.size(), sizeof(MyElement), compare_qsort);
	sort(vecOfData.begin(), vecOfData.end(), compare_sort);
	/*
	cout<< "Results After Sorting:"<<endl;
	for(i = 0; i < argc-1; i++)
	{
		cout<<setiosflags(ios::left)  <<setw(10)<< vecOfData[i].first << " , count: " << vecOfData[i].second << endl;
	}
	*/

	cout<<"Best is : "<<vecOfData[0].first <<" : with " << vecOfData[0].second * 100 / NUM_OF_ITERATIONS <<"%"<< endl;
	cin.get();
	return 0;
}