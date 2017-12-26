// BinaryTree.cpp: implementation of the BinaryTree class.
//
//////////////////////////////////////////////////////////////////////

#include "BinaryTree.h"
#include <iostream>

using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BinaryTree::BinaryTree()
{
	int iSize = 15;
	root = NULL;
	for (int i = 0; i < iSize; i++)
		InsertSorted(root, rand() % 10);
	Print(root);

	Find(root, 69) ? cout << 69 << " Found in tree!" << endl : cout << 69 << " Not Found in tree!" << endl;
	Find(root, 192) ? cout << 192 << " Found in tree!" << endl : cout << 192 << " Not Found in tree!" << endl;
	Find(root, -2) ? cout << -2 << " Found in tree!" << endl : cout << -2 << " Not Found in tree!" << endl;

	cout << "The Tree Has Sum : " << HasPathSum(root, 128) << endl;

	Delete(root);
	PrintAllPathes(root, PathesArray, 0);
}

BinaryTree::~BinaryTree()
{
}

BinaryTree::TreeNode::TreeNode()
{
	data = 0;
	left = right = NULL;
}

BinaryTree::TreeNode::~TreeNode()
{
};

bool BinaryTree::Find(TreeNode* root, int val)
{
	if (root == NULL)
		return false;
	if (root->data == val)
		return true;
	if (root->data < val)
		return Find(root->right, val);
	else
		return Find(root->left, val);
}

void BinaryTree::PrintArray(int array[], int iLength)
{
	for (int i = 0; i < iLength; i++)
		cout << array[i] << " ";
	cout << endl;
}

void BinaryTree::Delete(TreeNode*& root)
{
	if (!root)
		return;
	delete(root->left);
	delete(root->right);
	delete root;
	root = NULL;
}

void BinaryTree::Print(TreeNode* root)
{
	if (!root)
	{
		return;
	}

	static int iLevel = 0;
	cout << "Level :" << iLevel << " ";
	for (int i = 0; i < iLevel; i++)
		cout << "\t";

	cout << root->data << endl;
	iLevel++;
	Print(root->left);
	Print(root->right);
	iLevel--;
}


//1) /* Given two trees, return true if they are structurally identical */
int BinaryTree::identicalTrees(TreeNode* a, TreeNode* b){
	/*1. both empty */
	if (a == NULL && b == NULL)
		return 1;

	/* 2. both non-empty -> compare them */
	if (a != NULL && b != NULL)
	{
		return (a->data == b->data &&
			identicalTrees(a->left, b->left) &&
			identicalTrees(a->right, b->right));
	}
	/* 3. one empty, one not -> false */
	return 0;
}

//2) /* Computes the number of nodes in a tree. */
int BinaryTree::size(TreeNode* node){
	if (node == NULL)
		return 0;
	else
		return(size(node->left) + 1 + size(node->right));
}

//3)/* Compute number of nodes along the longest path from the root node down to the farthest leaf node.*/
int BinaryTree::maxDepth(TreeNode* node){
	if (node == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);
		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

//4) Tree Traversal:
void BinaryTree::printPostorder(TreeNode* node){
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->data);
}
void BinaryTree::printInorder(TreeNode* node){
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}
void BinaryTree::printPreorder(TreeNode* node){
	if (node == NULL)
		return;
	printf("%d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

//5)/*  This function traverses tree in post order to to delete each and every node of the tree */
void BinaryTree::deleteTree(TreeNode* node){
	if (node == NULL) return;
	deleteTree(node->left);
	deleteTree(node->right);
	printf("\n Deleting node: %d", node->data);
	free(node);
}

//6) Mirror tree
void BinaryTree::mirror(TreeNode* node){
	if (node == NULL)
		return;

	mirror(node->left);
	mirror(node->right);

	TreeNode* temp = node->left;
	node->left = node->right;
	node->right = temp;
}

//7)/* Recursive print out all the root-leaf paths. */
void BinaryTree::printPathsRecur(TreeNode* node, int path[], int pathLen){
	if (node == NULL) return;
	/* append this node to the path array */
	path[pathLen] = node->data;
	pathLen++;
	/* it's a leaf, so print the path that led to here */
	if (node->left == NULL && node->right == NULL)
	{
		PrintArray(path, pathLen);
	}
	else
	{
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

//8)/* Function to find Lowest Common Ancestor - LCA of n1 and n2. The function assumes that both n1 and n2 are present in BST */
BinaryTree::TreeNode* BinaryTree::lca(TreeNode* root, int n1, int n2){
	if (root == NULL) return NULL;
	// If both n1 and n2 are smaller than root, then LCA lies in left
	if (root->data > n1 && root->data > n2)
		return lca(root->left, n1, n2);
	// If both n1 and n2 are greater than root, then LCA lies in right
	if (root->data < n1 && root->data < n2)
		return lca(root->right, n1, n2);
	return root;
}

//9)/* Given a non-empty binary search tree, return the minimum data value found in that tree.*/
int BinaryTree::minValue(TreeNode* node){
	TreeNode* current = node;
	/* loop down to find the leftmost leaf */
	while (current->left != NULL) {
		current = current->left;
	}
	return(current->data);
}

//10) /* Function to print level order traversal a tree*/
/* Print nodes at a given level */
void BinaryTree::printGivenLevel(TreeNode* root, int level){
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}
void BinaryTree::printLevelOrder(TreeNode* root){
	int h = maxDepth(root);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(root, i);
}

//11)/* Function to get the count of leaf nodes in a binary tree*/
unsigned int BinaryTree::getLeafCount(TreeNode* node){
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return getLeafCount(node->left) + getLeafCount(node->right);
}

//12)/* Returns true if the given tree is a binary search tree efficient version). */
/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int BinaryTree::isBSTUtil(TreeNode* node, int min, int max){
	/* an empty tree is BST */
	if (node == NULL)
		return 1;
	/* false if this node violates the min/max constraint */
	if (node->data < min || node->data > max)
		return 0;
	/* otherwise check the subtrees recursively, tightening the min or max constraint */
	return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
}
int BinaryTree::isBST(TreeNode* node){
	return(isBSTUtil(node, INT_MIN, INT_MAX));
}

//13)/* Function to get diameter of a binary tree */
int BinaryTree::diameter(TreeNode * tree){
	/* base case where tree is empty */
	if (tree == 0)
		return 0;
	/* get the height of left and right sub-trees */
	int lheight = maxDepth(tree->left);
	int rheight = maxDepth(tree->right);
	/* get the diameter of left and right sub-trees */
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);
	/* Return max of following three
		1) Diameter of left subtree
		2) Diameter of right subtree
		3) Height of left subtree + height of right subtree + 1 */
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

//14)/* Returns true if binary tree with root as root is height-balanced */
bool BinaryTree::isBalanced(TreeNode *root){
	/* If tree is empty then return true */
	if (root == NULL) return 1;
	/* Get the height of left and right sub trees */
	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);
	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;
	/* If we reach here then tree is not height-balanced */
	return 0;
}

//15) print rows at K distance from the root
void BinaryTree::printKDistant(TreeNode *root, int k){
	if (root == NULL)
		return;
	if (k == 0)
	{
		printf("%d ", root->data);
		return;
	}
	else
	{
		printKDistant(root->left, k - 1);
		printKDistant(root->right, k - 1);
	}
}

//16) insert values in sorted order.
void BinaryTree::InsertSorted(TreeNode*& root, int data){
	if (root == NULL)
	{
		root = new TreeNode();
		root->data = data;
		cout << "Inserting : " << data << endl;
		return;
	}
	if (data > root->data)
		InsertSorted(root->right, data);
	else
		InsertSorted(root->left, data);
}

//17) insert values in complete order.
void BinaryTree::InsertComplete(TreeNode* root, int data){
	static int iLevel = 1;
	static int iNodesOnLevel = 0;

	if (!root->left)
	{
		root->left = new TreeNode();
		root->left->data = data;
		return;
	}
	if (!root->right)
	{
		root->right = new TreeNode();
		root->right->data = data;
		return;
	}
	if (!root->left->left || !root->left->right)
	{
		InsertComplete(root->left, data);
		return;
	}
	if (!root->right->left || !root->right->right)
	{
		InsertComplete(root->right, data);
		return;
	}
	InsertComplete(root->left, data);
}

//18) print all paths under root
void BinaryTree::PrintAllPathes(TreeNode* root, int array[], int iLength){
	if (root == NULL)
		return;

	array[iLength] = root->data;
	iLength++;

	if (root->left == NULL && root->right == NULL)
	{
		PrintArray(array, iLength);
		return;
	}

	PrintAllPathes(root->left, array, iLength);
	PrintAllPathes(root->right, array, iLength);
}

//19) the path from root has given sum
bool BinaryTree::HasPathSum(TreeNode* root, int sum){
	if (root == NULL)
	{
		return(sum == 0);
	}
	else
	{
		int iNewSum = sum - root->data;
		return HasPathSum(root->left, iNewSum) || HasPathSum(root->right, iNewSum);
	}
}
