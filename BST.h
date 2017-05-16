// BSTree.h ... interface to binary search tree ADT
// Written by John Shepherd, March 2013

#ifndef BSTREE_H
#define BSTREE_H

typedef struct BSTNode *BSTree;

typedef void (*Visit)(struct BSTNode *);

// create an empty BSTree
BSTree newBSTree();
// free memory associated with BSTree
void dropBSTree(BSTree);
// display a BSTree (sideways)
void showBSTree(BSTree);

// insert a new value into a BSTree
BSTree BSTreeInsert(BSTree, int);
BSTree BSTreeInsertI(BSTree, int);
// delete a value from a BSTree
BSTree BSTreeDelete(BSTree, int);


// generic traversal
void BSTreeTraverse(BSTree, Visit, char *);

#endif
