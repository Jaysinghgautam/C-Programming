#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTravesal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}

//case-1; deleting the first element from the linked list 
struct Node *deleteFirst(struct Node *head) {
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


//case-1; deleting the element at a given index from the linked list 
struct Node *deleteAtIndex(struct Node *head,int index) {
   struct Node *p = head;
   struct Node *q = head->next;
   for(int i =0; i<index-1; i++ ){
     p = p->next;
     q = q->next;
   }
   p->next = q->next;
   free(q);
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // allocate memory for nodes in the linked list iin heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes
    head->data = 7;
    head->next = second;

    // linke second to third
    second->data = 11;
    second->next = third;

    // terminate the linked list at the third node
    third->data = 66;
    third->next = NULL;
    printf("linked list before deletion\n");
    linkedListTravesal(head);

    head = deleteFirst(head);
    printf("linked list after deletion\n");
    linkedListTravesal(head);

    return 0;
}