// BSTree.h ... implementation of binary search tree ADT
// Written by John Shepherd, March 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "BSTree.h"

typedef struct BSTNode *Link;

typedef struct BSTNode {
	int  value;
	Link left, right;
} BSTNode;

// make a new node containing a value
static
Link newBSTNode(int v)
{
	//printf("Not yet implemented\n");
	Link new = malloc(sizeof(BSTNode));
	assert(new != NULL);
	new->value = v;
	new->left = new->right = NULL;
	return new;
}

// create a new empty BSTree
BSTree newBSTree()
{
	return NULL;
}

// free memory associated with BSTree
void dropBSTree(BSTree t)
{
	//printf("Not yet implemented\n");
	if (t == NULL) return;
	dropBSTree(t->left);
	dropBSTree(t->right);
	free(t);
}

#if 0
// display a BSTree (sideways)
static
void doShowBSTree(BSTree t, int level)
{
	printf("Not yet implemented\n");
}
#endif
void showBSTree(BSTree t)
{
	void doShowTree(BSTree);
	doShowTree(t);
#if 0
    //doShowBSTree(t,0);
#endif
}

// compute depth of BSTree
int BSTreeDepth(BSTree t)
{
	if (t == NULL)
		return 0;
	else {
		int ldepth = BSTreeDepth(t->left);
		int rdepth = BSTreeDepth(t->right);
		return 1 + ((ldepth>rdepth) ? ldepth : rdepth);
	}
}

// count #nodes in BSTree
int BSTreeNumNodes(BSTree t)
{
	int nnodes;
	if (t == NULL)
		nnodes = 0;
	else {
		int lnnodes = BSTreeNumNodes(t->left);
		int rnnodes = BSTreeNumNodes(t->right);
		nnodes = 1 + lnnodes + rnnodes;
	}
	return nnodes;
#if 0
	if (t == NULL)
		return 0;
	else
		return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
#endif
}

// check whether a value is in a BSTree
int BSTreeFind(BSTree t, int v)
{
	if (t == NULL)
		return 0; // didn't find the value
	else if (t->value == v)
		return 1;
	else if (t->value > v)
		return BSTreeFind(t->left, v);
	else
		return BSTreeFind(t->right, v);
}

int BSTreeFindI(BSTree t, int v)
{
	Link cur = t;
	while (cur != NULL) {
		if (cur->value == v)
			return 1;
		else if (cur->value > v)
			cur = cur->left;
		else
			cur = cur->right;
	}
	return 0;
}

// insert a new value into a BSTree
BSTree BSTreeInsert(BSTree t, int v)
{
	if (t == NULL)
		return newBSTNode(v);
	if (t->value == v)
		return t;
	else if (t->value > v) {
		t->left = BSTreeInsert(t->left, v);
		return t;
	}
	else {
		t->right = BSTreeInsert(t->right, v);
		return t;
	}
#if 0
	if (t->value > v)
		t->left = BSTreeInsert(t->left, v);
	else if (t->value < v)
		t->right = BSTreeInsert(t->right, v);
	return t;
#endif
}

BSTree BSTreeInsertI(BSTree t, int v)
{
	if (t == NULL)
		return newBSTNode(v);
		
	Link prev = NULL, cur = t;
	char dir;
	while (cur != NULL) {
		if (cur->value == v)
			return t;
		else if (cur->value > v) {
			dir = 'L';
			prev = cur;
			cur = cur->left;
		}
		else {
			dir = 'R';
			prev = cur;
			cur = cur->right;
		}
	}
	Link new = newBSTNode(v);
	if (dir == 'L')
		prev->left = new;
	else
		prev->right = new;
	return t;
}


// generic traversal
void BSTreeTraverse(BSTree t,
                    Visit visit,
                    char *style)
{
	if (t == NULL) return;
	if (strcmp(style,"NLR") == 0) (*visit)(t);
	BSTreeTraverse(t->left, visit, style);
	if (strcmp(style,"LNR") == 0) (*visit)(t);
	BSTreeTraverse(t->right, visit, style);
	if (strcmp(style,"LRN") == 0) (*visit)(t);
}

// delete a value from a BSTree
BSTree BSTreeDelete(BSTree t, int v)
{
	BSTree deleteRoot(BSTree);
	printf("Not yet implemented\n");
	return NULL;
}

// delete root of tree
BSTree deleteRoot(BSTree t)
{
	Link newRoot;
	// if no subtrees, tree empty after delete
	if (t->left == NULL && t->right == NULL) {
		free(t);
		return NULL;
	}
	// if only right subtree, make it the new root
	else if (t->left == NULL && t->right != NULL) {
		newRoot = t->right;
		free(t);
		return newRoot;
	}
	// if only left subtree, make it the new root
	else if (t->left != NULL && t->right == NULL) {
		newRoot = t->left;
		free(t);
		return newRoot;
	}
	// else (t->left != NULL && t->right != NULL)
	// so has two subtrees
	// - find inorder successor (grab value)
	// - delete inorder successor node
	// - move its value to root
	Link parent = t;
	Link succ = t->right; // not null!
	while (succ->left != NULL) {
		parent = succ;
		succ = succ->left;
	}
	int succVal = succ->value;
	t = BSTreeDelete(t,succVal);
	t->value = succVal;
	return t;
}

// Pretty tree printer

#include "show.c"
