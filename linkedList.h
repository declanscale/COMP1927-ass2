typedefine struct urlList{

 char *url
 struct urlList* next
  
}UL;


struct node *create_node(int data, struct urlList *next);
struct node *last(struct urlList *head);
struct node *append(struct urlList *head, int value);
