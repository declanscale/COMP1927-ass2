#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTLink;

typedef struct BSTNode {
	char* word;
	struct urlNode* url;
	BSTLink left, right;
} BSTNode;

static BSTLink newBSTNode(char word){
    
    BSTLink new = malloc(sizeof(BSTNode));
	assert(new != NULL);
	new->word = NULL;
	new->left = new->right = NULL;
	return new;

}


BSTree newBSTree(){
    
    
    
	return NULL;
}


void dropBSTree(BSTree t){
    
	if (t == NULL) return;
	dropBSTree(t->left);
	dropBSTree(t->right);
	free(t);
}


void showBSTreeNode(BSTree t)
{
	if (t == NULL) return;
	printf("%d ", t->value);
}

// print values in infix order
void BSTreeInfix(BSTree t)
{
	if (t == NULL) return;
	BSTreeInfix(t->left);
	showBSTreeNode(t);
	BSTreeInfix(t->right);
}


BSTree BSTreeInsert(BSTree t, char* newWord){
    
	if (t == NULL)
		return newBSTNode(newWord);
	else if (newWord[0] < t->word[0])
		t->left = BSTreeInsert(t->left, newWord);
	else if (newWord > t->value)
		t->right = BSTreeInsert(t->right, newWord);
	else // (v == t->value)
		/* don't insert duplicates */;
	return t;
}    // not sure if word[0] works 






