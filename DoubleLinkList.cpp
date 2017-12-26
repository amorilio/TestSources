// DoubleLinkList.cpp: implementation of the DoubleLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "DoubleLinkList.h"
#include <iostream>
#include <math.h>

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DoubleLinkList::Node* DoubleLinkList::insert(int val)
{
	Node* newNode = new Node(val);

	if (head)
	{
		newNode->next = head;
		head->prev = newNode;
	} else
	{
		tail = newNode;
	}
	head = newNode;
	return head;
}

DoubleLinkList::Node* DoubleLinkList::append(int val)
{
	return NULL;
}

DoubleLinkList::Node* DoubleLinkList::after(DoubleLinkList::Node* node, int val)
{
	return NULL;
}

DoubleLinkList::Node* DoubleLinkList::before(DoubleLinkList::Node* node, int val)
{
	return NULL;
}

void DoubleLinkList::print()
{
	Node* current = head;
	while(current)
	{
		cout<<current->data<<" ";
		current = current->next;
	}
}

void DoubleLinkList::unitTest()
{
	int iSize = 10;
	for(int i=0; i<iSize; i++)
	{
		insert(rand()%100);
	}
	print();
}