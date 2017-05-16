//Read data from a given collection of pages in collection.txt 
//and generates an "inverted index" that provides a list (set) of 
//urls for every word in a given collection of pages

#include <stdio.h>
#include <stdlib.h>
#include "readData.h"
#include "linkedList.h"
#include "BSTree.h"

void outputInvertedList(BSTLink invertedlist);

void invertedIndex() {
  urlNode list = GetCollection();
  BSTLink invertedlist = GetInvertedList(list);
  BSTreeInfix(invertedlist);
}

void outputInvertedList(BSTLink invertedlist) {
  FILE *fp = fopen("invertedIndex.txt", "w");
  BSTreeInfix(BSTree t)
}
