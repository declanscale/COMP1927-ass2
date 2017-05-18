#ifndef READDATA_H
#define READDATA_H

#include <stdio.h>

typedef struct GraphRep* Graph;
typedef struct BSTNode* BSTLink;
typedef struct urlNode* urlList;

urlList GetCollection();
Graph GetGraph(urlList list);
BSTLink GetInvertedList(urlList list);
void RemoveSpaces(char* source);

#endif
