#ifndef READDATA_H
#define READDATA_H

#include <stdio.h>

struct urlList* GetCollection();
Graph GetGraph(urlNode list);
BSTLink GetInvertedList(urlNode list);

#endif
