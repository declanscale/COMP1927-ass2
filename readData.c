#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "graph.h"
#include "BSTree.h"
define Max_URL_len 80
define Max_line_len 80

/*
struct node *create_node(int data, struct urlList *next);
struct node *last(struct urlList *head);
struct node *append(struct urlList *head, int value);
*/

urlNode GetCollection(){

    urlNode head = NULL;
    FILE *fp;
    char urlBuff[10];
    fp = fopen("collection.txt","r");

    while(!feof(fp)) { //while not end of the file

        fscanf(fp,"%s",urlBuff);
        
        head = append(head,urlBuff);
        
    }

    return head;

}


Graph GetGraph(urlNode list) {
  if (list == NULL) return NULL;
  urlNode temp = list;
  char *tempurl;
  char *tempstr0;
  char *tempstr1;
  int maxnum = countNumOfUrl(list);
  Graph g = newGraph(maxnum); //Create	empty	graph
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

BSTLink GetInvertedList(urlNode list) {
  if (list == NULL) return NULL;
  char *tempurl;
  BSTLink invertedlist = newBSTree();
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
        diff += strcmp(tempstr1, "Section-2");
      }
    }
    diff = 1;
    while(diff) { //read url
      if(fscanf(fp, "%s", tempstr0) == 0) { //if scanf nothing  //debug: maybe appending on the string
        break;
      } else {
        diff = strcmp(tempstr0, "#end");
        if(diff != 0) { //add link
          invertedlist = BSTreeInsert(invertedlist, tempstr0, temp->url);
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
  return invertedlist;
}
