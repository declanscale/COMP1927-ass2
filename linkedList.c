//create a linked list of URLs
#include "linkedList.h"



urlNode create_node(char *url, struct urlNode *next) {
    struct urlNode *n;

    n = malloc(sizeof (struct urlNode));
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

urlNode last(urlNode head) {
    if (head == NULL) {
        return NULL;
    }

    urlNode n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}



// create a new list node containing value
// and append it to end of list

urlNode append(urlNode head, char *url) {
    // new node will be last in list, so next field is NULL
    urlNode n =  create_node(url, NULL);
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

int countNode(urlNode head){

    int num = 0;
    struct urlNode *curr = head;

    if(head->next == NULL){
        return 0;
    }else{

        while(head->next !=NULL){
            num++;
            curr = curr->next;
        }

        return num;

    }

}

urlNode deleteNode(urlNode head, urlNode node){
    struct urlNode *curr = head;
    struct urlNode *tempNode = NULL;
    
    while(curr != NULL){
        if(curr->url == node->url){
               tempNode = curr;
               curr->next = curr->next->next;
               free(tempNode);
        }
        curr = curr->next;
    }
    
    return head;
    
}

