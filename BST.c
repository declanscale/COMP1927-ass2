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


void showBSTreeNode(BSTree t) //output to file
{
	if (t == NULL) return;
	struct urlNode* tempurl = t->url;
	FILE *fp = fopen("invertedIndex.txt", "a");
	if(fp == NULL){
		printf("Error opening file\n");
		return NULL;
	}
	fprintf(fp, "%s  ", t->word);
	int isvalid = 1;
	while(isvalid) {
		fprintf(fp, "%s ", tempurl->url);
		if(tempurl->next != NULL) {
			tempurl = tempurl->next;
		} else {
			isvalid = 0;
		}
	}
	fprintf(fp, "\n");
	fclose(fp);
}

// print values in infix order
void BSTreeInfix(BSTree t)
{
	if (t == NULL) return;
	BSTreeInfix(t->left);
	showBSTreeNode(t); //output to file
	BSTreeInfix(t->right);
}


BSTree BSTreeInsert(BSTree t, char* newWord, char* url){
    
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

