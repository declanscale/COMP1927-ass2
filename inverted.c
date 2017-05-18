
//Read data from a given collection of pages in collection.txt
//and generates an "inverted index" that provides a list (set) of
//urls for every word in a given collection of pages

#include <stdio.h>
#include <stdlib.h>
#include "readData.h"
#include "linkedList.h"
#include "BST.h"
#include "graph.h"

void outputInvertedList(struct BSTNode invertedlist);

void invertedIndex() {
  struct urlNode list = GetCollection();
  struct BSTNode invertedlist = GetInvertedList(list);
  BSTreeInfix(invertedlist); //output to file
}
