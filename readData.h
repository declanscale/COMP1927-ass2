#ifndef READDATA_H
#define READDATA_H

#include <stdio.h>

struct urlList GetCollection();
struct GraphRep GetGraph(struct urlList list);
struct BSTNode GetInvertedList(struct urlList list);
void RemoveSpaces(char* source);

#endif
