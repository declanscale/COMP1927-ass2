#include <stdio.h>
#include <stdlib.h>
#include "readData.h"
#include "linkedList.h"
#include "graph.h"


void PageRank(int d, int diffPR, int maxIterations);

int main(int argc, char *argv[]) {

  int dampingFactor = 0;
  int differPR = 0;
  int maxIterition = 0;
//need a standard input
  urlNode list = GetCollection();
  Graph graph = GetGraph(list);
  PageRank(d, diffPR, maxIterations);
  return 0;
}

void PageRank(int d, int diffPR, int maxIterations) {

	int N = graph->nV;
	int iteration = 0;
	int diff = diffPR;

	int urlPr[N];//an array to store the pr of url
	int initailPr = 1/N;//initial pr for every url
	
	while(i < N){ //give every url an initial pr
        urlPr[i] = initailPr;
        i++;
	}
	
	int i = 0;//raw counter
	int j = i+1;//col counter
	int numofOutLink = 0;
	int temp = 0;//store the temp url
	int k = 0;//diff counter
	
	while(iteration < maxIterations && diff >= diffPR){
        while(i < N){
            while(j < N){
                if(graph->edge[i][j]!=0){ // find the come in link
                    temp = i;//store the current url
                    i = 0;
                    while(i < N){//count how many out link of current url
                        if(graph->edge[i][j]!=0){
                            numofOutLink++;//L(Pi)
                        }
                        i++;
                    }
                    
                    urlPr[temp] = ((1-d)/N) + (urlPr[j]/numofOutLink); // add pr to current url 
                }
                j++;
                i = temp;
            }
            i++;
        }
        i = 0; //reset to start another iteration
        j = i+1; // reset
        iteration++;
        k = 0;
        while(k < N){
            diff = diff + abs(urlPr[k]-urlPr[k+1]);
            k++;
        }
	}
	
	



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
