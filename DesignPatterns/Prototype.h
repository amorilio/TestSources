// Prototype.h: interface for the Prototype class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROTOTYPE_H__690C4E20_2F50_45B0_8196_2FA890E14618__INCLUDED_)
#define AFX_PROTOTYPE_H__690C4E20_2F50_45B0_8196_2FA890E14618__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define NUM_OF_NODES 10

enum TreeNodeTypes
{
	Base_Tree_Node		= 0,
	Tree_Node			= 1,
	Tree_Node_LPL		= 2,
	Tree_Node_IGL		= 3,
	Tree_Node_IRL		= 4
};

class BaseNode
{
public:
	virtual ~BaseNode(){};
	virtual BaseNode* clone()		= 0;
	virtual int getId()				= 0;
	virtual const char* getName()	= 0;

	static BaseNode* findAndClone(TreeNodeTypes tnt)
	{
		return prototypes[tnt]->clone();
	};

    static void addPrototype(BaseNode *tn)
    {
		int id = tn->getId();
        prototypes[id] = tn;
    }
protected:
	BaseNode(){};
private:

    static BaseNode* prototypes[10];
};

class TreeNode : public  BaseNode
{
public:
	TreeNode()				{addPrototype(this);}
	~TreeNode(){};
	BaseNode* clone()		{return new TreeNode();};
	int getId()				{return Tree_Node_LPL ;};
	const char*  getName()	{return "TreeNode";};
private:
	//static TreeNode _TreeNode;
};

class TreeNodeLPL : public BaseNode
{
public:
	TreeNodeLPL()			{addPrototype(this);}
	~TreeNodeLPL(){};
	BaseNode * clone()		{return new TreeNodeLPL();};
	int getId()				{return Tree_Node;};
	const char*  getName()	{return "TreeNodeLPL";};
private:
	//static TreeNodeLPL _TreeNodeLPL;
};

class TreeNodeIGL : public BaseNode
{
public:
	TreeNodeIGL()			{addPrototype(this);}
	~TreeNodeIGL(){};
	BaseNode * clone()		{return new TreeNodeIGL();};
	int getId()				{return Tree_Node_IGL;};
	const char*  getName()	{return "TreeNodeIGL";};
private:
	//static TreeNodeIGL _TreeNodeIGL;
};

class TreeNodeIRL : public BaseNode
{
public:
	TreeNodeIRL()			{addPrototype(this);}
	~TreeNodeIRL(){};
	BaseNode * clone()		{return new TreeNodeIRL();};
	int getId()				{return Tree_Node_IRL;};
	const char*  getName()	{return "TreeNodeIRL";};
private:
	//static TreeNodeIRL _TreeNodeIRL;
};

extern void ClientPrototype();

#endif // !defined(AFX_PROTOTYPE_H__690C4E20_2F50_45B0_8196_2FA890E14618__INCLUDED_)
