// Composite.h: interface for the Composite class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPOSITE_H__F762454E_D062_497A_8573_BD7A6C350F2D__INCLUDED_)
#define AFX_COMPOSITE_H__F762454E_D062_497A_8573_BD7A6C350F2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <vector>

class Component
{
public:
	virtual ~Component(){};
	virtual void print() = 0;
protected:
	Component(int i){};
	Component(){};
};

class Composite : public Component
{
public:
	Composite(){};
	Composite(int i) : data(i) {}
	~Composite(){};

	void addChild(Component *c)
	{
		children.push_back(c);
	}
	void print()
	{
		std::cout<<data<<" ";
		int size = children.size();
		for (int i = 0; i < size; i++)
			children[i]->print();
		std::cout<<std::endl;
	}
private:
	std::vector<Component *> children;
	int data;
};

class Simple: public Component
{
public:
	Simple(){};
	Simple(int i) : data(i) {}
	~Simple(){};
	void print()
	{
		std::cout<<data<<" "<<std::endl;
	}
private:
	int data;
};

extern void ClientComposite();

#endif // !defined(AFX_COMPOSITE_H__F762454E_D062_497A_8573_BD7A6C350F2D__INCLUDED_)
