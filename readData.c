//List_of_Urls <- GetCollection()
//Create a set (list) of urls to process by reading	data from	file “collection.txt”
//Graph	g	<- GetGraph(List_of_Urls)
//Create	empty	graph	(use graph ADT in say	graph.h and	graph.c)
//For	each url in the	above	list	
//read <url>.txt file,	and	update graph by adding a node and outgoing links	
//InvertedList <- GetInvertedList(List_of_Urls )
//Create empty inverted list (use	say	List of	lists, BST where values	are	lists, etc)
//For	each	url in	List_of_Urls
//read <url>.txt file, and update inverted index

#include <stdio.h>
#include <stdlib.h>
#inlcude <string.h>
#include "Graph.h"



Graph GetGraph(UL list) {
  if (list == NULL || list->num == 0) return NULL;
  UL temp = list->first;
  char *tempurl;
  Graph g = newGraph(list->num);
  int isvalid = 1;
  while(isvalid) {
    strcpy(tempurl, temp->url); //debug: maybe appending on the string
    strcat (tempurl, ".txt");
    FILE *fp = fopen (tempurl, "r");
    
    if (temp->next != NULL) {
      temp = temp->next;
    } else {
      isvalid = 0;
    }
}
