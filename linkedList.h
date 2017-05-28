#ifndef LINKEDLIST_H
#define LINKEDLIST_H


struct urlNode{
 char *url;
 struct urlNode* next;
};

typedef struct urlNode* urlNode;


urlNode create_node(char* url, struct urlNode *next);
urlNode last(struct urlNode *head);
urlNode append(struct urlNode *head, char* url);
int countNode(struct urlNode* head);
urlNode deleteNode(urlNode head, urlNode node);


#endif
