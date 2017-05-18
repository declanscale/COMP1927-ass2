typedef struct urlNode{
    char *url;
    struct urlNode* next;
} *urlList;


struct node *create_node(char* url, struct urlNode *next);
struct node *last(struct urlNode *head);
struct node *append(struct urlNode *head, char* url);
int countNumOfUrl(struct urlNode* head);
