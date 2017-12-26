// SingleLinkList.h: interface for the SingleLinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLELINKLIST_H__5E8E3818_C5BE_483A_9E9E_AF414CF1FDED__INCLUDED_)
#define AFX_SINGLELINKLIST_H__5E8E3818_C5BE_483A_9E9E_AF414CF1FDED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class Node
{
public:
	Node() : data(0), next(0) {}
	Node(int d, Node* n = 0) : data(d), next(n) {}
	int data;
	Node *next;
};

class SingleLinkList
{
public:
	SingleLinkList();
	virtual ~SingleLinkList();

	Node* CreateRandomList(int iSize);

	void add (Node **node,int data);
	void print(Node* node);
	void printReverse(Node * node);

	void insertSorted(Node **node,int num);
	void removeDuplicates();

	void findNTHElementFromTheEnd(int nthElement);
	Node*  findMiddleNode(Node* node);

	void checkIfListCyclic();
	void makeListCyclic();

	void copyTheList(Node **trg, Node* src);

	void reverseListIterative(Node **node);
	void reverseListRecursive(Node *node);

	void compareLists(Node* list1, Node* list2);
	void destroyTheList(Node **node);

	void swap(Node* p1,Node* p2);

	void bubbleSort(Node **node);
	void bubbleSort2(Node **head);

	void mergeSort(Node **node);
	Node* merge(Node *, Node *);

private:
	Node *head;
};

#endif // !defined(AFX_SINGLELINKLIST_H__5E8E3818_C5BE_483A_9E9E_AF414CF1FDED__INCLUDED_)
