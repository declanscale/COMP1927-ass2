#ifndef READDATA_H
#define READDATA_H

#include <stdio.h>
#include "graph.h"
#include "linkedList.h"

struct urlNode GetCollection();
struct GraphRep GetGraph(urlNode list);
struct BSTNode GetInvertedList(urlNode list);

#endif