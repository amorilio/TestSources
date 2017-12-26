// Stack.cpp: implementation of the Stack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Stack.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

template <typename T>
Stack<T>::Stack(int capacity) : _capacity(capacity), _top(-1)
{
	//_array = new T(_capacity);
	_array = new char(_capacity);
}

template <typename T>
Stack<T>::~Stack()
{
	//delete [] _array;
}

template <typename T>
void	Stack<T>::push(T obj)
{
	if(_top == _capacity)  throw StackIsFull();

	_top = _top + 1;
	printf("Stack Capacity %d, Insert At %d\n", _capacity, _top);

	_array[_top] = obj;
}

template <typename T>
T		Stack<T>::pop()
{
	if(_top == -1)  throw StackIsEmpty();

	printf("Stack Capacity %d, Pop From %d\n", _capacity, _top);

	return _array[_top--];
}

template <typename T>
bool	Stack<T>::isEmpty()
{
	return (_top == -1);
}

template <typename T>
bool	Stack<T>::isFull()
{
	return (_top == (_capacity - 1));
}

void StackTest()
{
	int i=0;
	Stack<char>* myStack = new Stack<char>(32);
	char testString[32];

	sprintf(testString, "abcde");
	printf("\n--------------- Stack Test--------------- \n");
	printf("String Before: %s\n",testString);

	int iLen = strlen(testString);

	for( i=0 ; i < iLen; i++)
		myStack->push(testString[i]);
	for( i=0 ; i < iLen; i++)
		testString[i] = myStack->pop();

	delete myStack;
	printf("String After: %s\n",testString);
	printf("--------------- Stack Test--------------- \n");
}