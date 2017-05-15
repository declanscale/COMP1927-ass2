//create a linked list of URLs


struct urlList *create_node(char *url, struct urlList *next) {
    struct urlList *n;

    n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->url = url;
    n->next = next;
    return n;
}

// return pointer to last node in list
// NULL is returned if list is empty

struct urlList *last(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct urlList *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}


// create a new list node containing value
// and append it to end of list

struct urlList *append(struct urlList *head, char *url) {
    // new node will be last in list, so next field is NULL
    struct urlList *n =  create_node(url, NULL);
    if (head == NULL) {
        // new node is now  head of the list
        return n;
    } else {
        // change next field of last list node
        // from NULL to new node
        last(head)->next = n;  /* append node to list */
        return head;
    }
}

int countNode(struct urlList *head){
    
    int num = 0;
    struct urlList *curr = head;
    
    if(head->next == NULL){
        return 0;
    }else{
        
        while(head->next !=NULL){
            n++;
            curr = curr->next;
        }
        
        return n;
        
    }
    
}
