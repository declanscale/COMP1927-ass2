#ifndef BSTREE_H
#define BSTREE_H

/*
//typedef struct BSTNode *BSTLink;

//typedef void (*Visit)(struct BSTNode *);

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
*/

struct BSTNode newBSTNode(char* word, char* newUrl);
void showBSTreeNode(struct BSTNode t);
void BSTreeInfix(struct BSTNode t);
struct BSTNode BSTreeInsert(struct BSTNode t, char* newWord, char* url);




#endif
