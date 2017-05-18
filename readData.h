#ifndef READDATA_H
#define READDATA_H

#include <stdio.h>

typedef struct GraphRep *Graph;
typedef struct BSTNode *BSTLink

struct urlList* GetCollection();
Graph GetGraph(struct urlList* list);
BSTLink GetInvertedList(urlNode list);
void RemoveSpaces(char* source);

#endif
