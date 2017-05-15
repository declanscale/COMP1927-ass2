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
#include <string.h>
#include "linkedList.h"
#include "graph.h"
define Max_URL_len 80
define Max_line_len 80
  
/*  
struct node *create_node(int data, struct urlList *next);
struct node *last(struct urlList *head);
struct node *append(struct urlList *head, int value); 
*/  
  
struct urlList* GetCollection(){
  
  struct urlList* head = NULL;
  FILE* fp;
  char* line[Max_lineL_len];
  int n = Max_line_len;
  char* url[Max_url_len];
  
  fp = fopen("collection.txt","r");
  
  while(!feof(fp)) {
    
    fegets（char *line, int n, FILE* fp);
    url = strtok(line," ")；
      
    while(url!=NULL){
      
      head =  append(head, url);
      url = strok(line," ");
      
    }
  }
  
}
 
Graph GetGraph(UL list) {
  if (list == NULL || list->num == 0) return NULL;
  UL temp = list->first;
  char *tempurl;
  char *tempstr0;
  char *tempstr1;
  Graph g = newGraph(list->num); //Create	empty	graph
  int diff = 1;
  int isvalid = 1;
  while(isvalid) { //open url file
    strcpy(tempurl, temp->url); //debug: maybe appending on the string
    strcat (tempurl, ".txt");
    FILE *fp = fopen (tempurl, "r");
    if(fp == NULL) {
      printf("Error opening file\n");
      return NULL;
    }
    while(diff) { //read "#start Section-1"
      if(fscanf(fp, "%s %s", tempstr0, tempstr1) == 0) { //if scanf nothing
        break;
      } else {
        diff = strcmp(tempstr0, "#start");
        diff += strcmp(tempstr1, "Section-1");
      }
    }
    diff = 1;
    while(diff) { //read url
      if(fscanf(fp, "%s", tempstr0) == 0) { //if scanf nothing  //debug: maybe appending on the string
        break;
      } else {
        diff = strcmp(tempstr0, "#end");
        if(diff != 0) { //add link
          addEdge(g, temp->url, tempstr0);
        }
      }
    }
    fclose(fp);
    if (temp->next != NULL) {
      temp = temp->next;
    } else {
      isvalid = 0;
    }
  }
  return g;
}
