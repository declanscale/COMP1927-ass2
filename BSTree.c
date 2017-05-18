#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode *BSTLink;

typedef struct BSTNode {
	char* word;
	struct urlNode* url;
	BSTLink left, right;
} BSTNode;

static BSTLink newBSTNode(char* word, char* url){
    
  BSTLink new = malloc(sizeof(BSTNode));
	assert(new != NULL);
	new->word = word;
	new->left = new->right = NULL;
	new->url->next = append(new->url, url);
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



// use recursive function to insert node and add the url list at the same time
BSTree BSTreeInsert(BSTree t, char* newWord, char* url){
  
	if (t == NULL)
		return newBSTNode(newWord, url);
	else{
		if(strcmp(newWord,t->word)<0)
			BSTreeInsert(t->left,newWord,url);
		else if(strcmp(newWord,t->word)>0)
			BSTreeInsert(t->right,newWord,url);
		else
			append(t->url,url);				
	}
	
	return t;
}   

