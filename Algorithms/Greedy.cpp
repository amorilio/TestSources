#include "stdafx.h"
#include "Greedy.h"

#include <vector>

using namespace std;
//
//	TODO: Implement according to lecture : https://www.youtube.com/watch?v=evg9tvgS1GA
//
//	1. numbers . find minimal number of fixed sections to cover all points.
//	2. meetings. There are list of meetings (start - end) find the sequense of maximal meetings to attend.
//	3. Party Planning. Input is a tree. Find maximal nubmer of employs to invite to the party , so that their managers will not be invited.
//	4. Having a 'bag' and list of things <-> costs. find optimal number of things to fit into the bag , so that the amount of the bag will be maximal
//
//	Huffman codding
//




vector<pair<int, int>>	getOptimalSectionsList(vector<int> arr, int sectionWidth)
{
	vector<pair<int, int>> out;
	return out;
}

vector<pair<int, int>>	getOptimalMeetingsList(vector<pair<int, int>>)
{
	vector<pair<int, int>> out;
	return out;
}

struct Employee
{
	string name;
	vector<Employee> workers;
};

vector<Employee> partyPlanning(vector<pair<int, int>>)
{
	vector<Employee> out;
	return out;
}


struct Thing
{
	int weight;
	int price;
};
vector<Thing> optimalThingsInBag(vector<Thing> allThings, int iBagSize)
{
	vector<Thing> out;
	return out;
}






