#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "linkedList.c"
#include <string.h>

typedef struct BSTNode *BSTNode;

struct BSTNode {
	char* word;
	struct urlNode* urlHead;
	BSTNode left, right;
};

static BSTNode newBSTNode(char* word, char* newUrl){

    BSTNode new = malloc(sizeof(BSTNode));
	//assert(new != NULL);
	new->word = word;
	new->left = new->right = NULL;
	new->urlHead->next = NULL;
        new->urlHead = append(new->urlHead, newUrl);
	return new;

}

/*
BSTree newBSTree(){
	return NULL;
}
*/

void dropBSTree(BSTNode t){

	if (t == NULL) return;
	dropBSTree(t->left);
	dropBSTree(t->right);
	free(t);
}


void showBSTreeNode(BSTNode t) //output to file
{
	if (t == NULL) return;
	urlNode tempurl = t->urlHead;
	FILE *fp = fopen("invertedIndex.txt", "a");
	if(fp == NULL){
		printf("Error opening file\n");
		return;
	}
	fprintf(fp, "%s  ", t->word);
	int isvalid = 1;
	while(isvalid) {
		fprintf(fp, "%s ", tempurl);
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
void BSTreeInfix(BSTNode t)
{
	if (t == NULL) return;
	BSTreeInfix(t->left);
	showBSTreeNode(t); //output to file
	BSTreeInfix(t->right);
}



// use recursive function to insert node and add the url list at the same time
BSTNode BSTreeInsert(BSTNode t, char* newWord, char* url){

	if (t == NULL)
		return newBSTNode(newWord, url);
	else{
		if(strcmp(newWord,t->word)<0)
			BSTreeInsert(t->left,newWord,url);
		else if(strcmp(newWord,t->word)>0)
			BSTreeInsert(t->right,newWord,url);
		else
			append(t->urlHead,url);
	}

	return t;
}
