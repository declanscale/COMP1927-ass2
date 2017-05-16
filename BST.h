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
BSTree BSTreeInsert(BSTree, char*);
//BSTree BSTreeInsertI(BSTree, char*);
// delete a value from a BSTree
BSTree BSTreeDelete(BSTree, char*);
void BSTreeInfix(BSTree t);


// generic traversal
//void BSTreeTraverse(BSTree, Visit, char *);

#endif
