typedefine struct urlNode{
 char *url
 struct urlNode* next
}UL;

typedefine struct urlListRep{
 int num;
 struct urlNode* first
 struct urlNode* last
}urlList;


struct node *create_node(int data, struct urlList *next);
struct node *last(struct urlList *head);
struct node *append(struct urlList *head, int value);
