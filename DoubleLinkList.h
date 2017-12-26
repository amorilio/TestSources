// DoubleLinkList.h: interface for the DoubleLinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOUBLELINKLIST_H__FB87E1E7_E24F_4963_90F4_A97CCD0450CE__INCLUDED_)
#define AFX_DOUBLELINKLIST_H__FB87E1E7_E24F_4963_90F4_A97CCD0450CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class DoubleLinkList
{
public:

	class Node
	{
	public:
		Node(int val) : data(val), prev(0), next(0) {}
		int data;
		Node* prev;
		Node* next;
	};

	DoubleLinkList()
	{
		head = tail = 0;
	};
	virtual ~DoubleLinkList()
	{
	};

	Node* insert(int val);
	Node* append(int val);
	Node* after(Node* node, int val);
	Node* before(Node* node, int val);

	void print();

	void unitTest();

private:
	Node* head;
	Node* tail;
};

#endif // !defined(AFX_DOUBLELINKLIST_H__FB87E1E7_E24F_4963_90F4_A97CCD0450CE__INCLUDED_)
