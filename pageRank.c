//Read data from a given collection of pages in the file collection.txt
//and builds a graph structure using Adjacency Matrix or List Representation

#include <stdio.h>
#include <stdlib.h>
#include "readData.h"
#include "linkedList.h"
#include "graph.h"

void PageRank(d, diffPR, maxIterations) {
  urlNode list = GetCollection();
  Graph graph = GetGraph(list);
}
