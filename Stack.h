// Stack.h: interface for the Stack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__E05B5549_26B3_4B11_B58B_5BD4E9DDCF51__INCLUDED_)
#define AFX_STACK_H__E05B5549_26B3_4B11_B58B_5BD4E9DDCF51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern void StackTest();

template <typename T>
class Stack
{
public:
	Stack(int capacity);
	virtual ~Stack();

	class StackIsFull{};
	class StackIsEmpty{};

	void	push(T obj);
	T		pop();
	bool	isEmpty();
	bool	isFull();
private:
	int _capacity;
	int _top;
	//T*	_array;
	char*	_array;
};

#endif // !defined(AFX_STACK_H__E05B5549_26B3_4B11_B58B_5BD4E9DDCF51__INCLUDED_)
