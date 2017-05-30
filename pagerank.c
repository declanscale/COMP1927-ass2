#include <stdio.h>
#include <stdlib.h>
#include "readData.h"
#include "linkedList.h"
#include "graph.h"
#include <string.h>
#include <math.h>
#define EPS 0.0000001


void PageRank(double d, double diffPR, int maxIterations);


int main(int argc, char *argv[]) {

  
  double d = atof(argv[1]);
  double diffPR = atof(argv[2]);
  int max = atoi(argv[3]);
  
  PageRank(d, diffPR, max);
  
  return 0;
}

void PageRank(double d, double diffPR, int maxIterations) {

    urlNode list = GetCollection();
    Graph graph = GetGraph(list);
    
    printf("d = %lf, diffPR = %lf\n",d, diffPR);
	double N = graph->nV;
	int totalNum = graph->nV;
	
	printf("total num is %d\n",totalNum);
	
	printf("number of vertex is %lf\n",N);
	
	int iteration = 0;
	double diff = diffPR;
	
	int i = 0;//raw counter
	int j = 0;//col counter
	
	int temp = 0;//store the temp url
	int k = 0;//diff counter
	
	
	showGraph(graph,1);//test for matrix

	double oldPr[totalNum];//an array to store the pr of url in previous iteration
	double newPr[totalNum];//store the pr in new iteration
	
	while(i < totalNum){ //give every url an initial pr
	
        oldPr[i] = 1/N;
        newPr[i] = 0;
        i++;
	}

	int* numofLink = malloc(sizeof(int)*totalNum);//check how many link between url
	
	for (i=0; i<totalNum; i++) {
	    numofLink[i] = 0;
	    temp = 0;
	    while(temp < totalNum){
	        if(graph->edges[i][temp] == 1 && temp != i){  
	            numofLink[i]++;         
	         }
	         temp++;
	    }

	}
	
	while(iteration < maxIterations && (diff >= diffPR)) {

	    j = 0;
	    while(j<totalNum) {
	        i=0;
	        while(i<totalNum) {
	            //for each i that links to j add oldPr[i]/numofLink[i] to newPr[j]
	            if(graph->edges[i][j] == 1 && j != i  ) {
	                newPr[j] += oldPr[i]/numofLink[i];                
	            }
                i++;    
	        }
	        
	        newPr[j] = (1.0-d)/N + d*newPr[j];//calculate the pageRank
	        j++;
	        k = 0; 

	    }

	    k = 0;//count diff
	    diff = 0;
        while(k < totalNum) {
            diff += fabs(newPr[k]-oldPr[k]);
            k++;
        }
        k=0;	    
	    while(k<totalNum){
	        oldPr[k] = newPr[k];
	        newPr[k] = 0;
	        k++;
	     }
	     
        iteration++;
    }
    
    
/*
    while(k<totalNum){
        p    k = 0;rintf(" Before sorted, pr of %d url is %lf\n",k, oldPr[k]);
        k++;
    }
    
*/    
    
    char* urlName[totalNum]; //create an array to store url name
    int urlIndex[totalNum];//store the index of url
    urlNode currUrl = list;
    
    
    k = 0;
    while(k<totalNum){
    
        urlIndex[k] = k;
        k++;
    
    }
    
    
    
    k = 0;
    
    while(k<totalNum){
    
        urlName[k] = strdup(currUrl->url);
        currUrl = currUrl->next;
//        printf("%d url is %s\n",k,urlName[k]);
        k++;
    
    }
    
    
    
    i = 0;
    j = 0; 
    double swapPr;
    int swapIndex;
    
//    char* swapUrl;
//    swapUrl = urlName[1];
//    printf("first url is %s\n",swapUrl);
    
    for(i = 0; i < totalNum; i++){
    
        for(j = 0; j < totalNum-i;j++){
        
            if(oldPr[j]<oldPr[j+1]){
            
                swapPr = oldPr[j];
                swapIndex = urlIndex[j];
                
                
                
                oldPr[j] = oldPr[j+1];
                urlIndex[j] = urlIndex[j+1];
                
                
                oldPr[j+1] = swapPr;
                urlIndex[j+1] = swapIndex;
                       
            
            }
        
        }
    
    }
    
 /*   
    k = 0;
    while(k<totalNum){
        printf("After sorted pr of %d url is %lf\n",k, oldPr[k]);
        k++;
    }
    
    k = 0;
    while(k<totalNum){
    
        printf("after sorted, url order is %d\n",urlIndex[k]);
        k++;
    
    }

*/    
    int totalLink[totalNum];
    
    i = 0;
    k = 0;
    int countLink = 0;
    
    while(k<totalNum){
    
        while(i<totalNum){
        
            if(graph->edges[k][i]!=0){
                countLink++;
            }
            i++;
        }
        totalLink[k] = countLink;
        countLink = 0;
        i = 0;
        k++;
    
    }


    
    
    FILE *f;
    
    f = fopen("pageRankListNew.txt","w");
    k = 0;
    while(k<totalNum){
    
        fprintf(f,"%s, %d, %.7lf\n",urlName[urlIndex[k]],totalLink[urlIndex[k]],oldPr[k]);
        k++;
    
    }
    
    
/*    
    int array[totalNum];
    k = 0;
    while(k<totalNum){
    
        array[k] = graph->edges[k][0];
        k++;
    
    }
    
    k = 0;
    while(k<totalNum){
    
    
        printf("link of url11 are %d\n",array[k]);
        k++;
    
    
    }
    
*/
    
     
    
    
}








