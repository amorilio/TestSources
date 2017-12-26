// BinaryTree.h: interface for the BinaryTree class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BINARYTREE_H__855CAD08_08F7_4445_A572_DCC17DB21CF0__INCLUDED_)
#define AFX_BINARYTREE_H__855CAD08_08F7_4445_A572_DCC17DB21CF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class BinaryTree
{
public:

	class TreeNode
	{
	public:
		int data;
		TreeNode* left;
		TreeNode* right;

		TreeNode();
		virtual ~TreeNode();
	};

	BinaryTree();
	virtual ~BinaryTree();

	bool Find(TreeNode* root, int val);
	void InsertComplete (TreeNode* root, int data);
	void InsertSorted (TreeNode*& root, int data);
	void Delete(TreeNode*& root);

	void Print (TreeNode* root);
	void PrintAllPathes(TreeNode* root, int array[], int iLength);

	int size(TreeNode* node);
	bool HasPathSum(TreeNode* root, int sum);
	int identicalTrees(TreeNode* a, TreeNode* b);
	int maxDepth(TreeNode* node);
	void printPostorder(TreeNode* node);
	void printInorder(TreeNode* node);
	void printPreorder(TreeNode* node);
	void deleteTree(TreeNode* node);
	void mirror(TreeNode* node);
	int minValue(TreeNode* node);
	void printPathsRecur(TreeNode* node, int path[], int pathLen);
	TreeNode *lca(TreeNode* root, int n1, int n2);
	void printLevelOrder(TreeNode* root);
	unsigned int getLeafCount(TreeNode* node);
	int isBST(TreeNode* node);
	int diameter(TreeNode * tree);
	bool isBalanced(TreeNode *root);
	void printKDistant(TreeNode *root , int k);

private:
	TreeNode* root;
	int PathesArray[100];

	void PrintArray(int array[], int iLength);
	void printGivenLevel(TreeNode* root, int level);
	int isBSTUtil(TreeNode* node, int min, int max);
};

#endif // !defined(AFX_BINARYTREE_H__855CAD08_08F7_4445_A572_DCC17DB21CF0__INCLUDED_)
