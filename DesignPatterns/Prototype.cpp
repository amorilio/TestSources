// Prototype.cpp: implementation of the Prototype class.
//
//////////////////////////////////////////////////////////////////////

#include "Prototype.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include <iostream>

BaseNode* BaseNode::prototypes[];

//TreeNode	  TreeNode::_TreeNode;
//TreeNodeLPL TreeNodeLPL::_TreeNodeLPL;
//TreeNodeIGL TreeNodeIGL::_TreeNodeIGL;
//TreeNodeIRL TreeNodeIRL::_TreeNodeIRL;

void ClientPrototype()
{
	BaseNode::addPrototype(new TreeNode());
	BaseNode::addPrototype(new TreeNodeLPL());
	BaseNode::addPrototype(new TreeNodeIGL());
	BaseNode::addPrototype(new TreeNodeIRL());

	TreeNodeTypes input[NUM_OF_NODES] =
	{
		Tree_Node_IRL,
		Tree_Node_LPL,
		Tree_Node_LPL,
		Tree_Node,
		Tree_Node,
		Tree_Node_IGL,
		Tree_Node_IGL,
		Tree_Node_IRL,
		Tree_Node_IGL,
		Tree_Node_LPL
	};
	BaseNode *Nodes[NUM_OF_NODES];

	// Given an image type, find the right prototype, and return a clone
	for (int i = 0; i < NUM_OF_NODES; i++)
		Nodes[i] = BaseNode::findAndClone(input[i]);

	// Demonstrate that correct image objects have been cloned
	for (int i = 0; i < NUM_OF_NODES; i++)
		std::cout<<Nodes[i]->getName()<<std::endl;

	// Free the dynamic memory
	for (int i = 0; i < NUM_OF_NODES; i++)
		delete Nodes[i];
}