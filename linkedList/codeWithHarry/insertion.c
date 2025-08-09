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

// insert at first
struct Node *instertFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// insert at end
struct Node *instertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return ptr;
}

// insert at index
struct Node *insertAtIndex(struct Node *head, int data, int index)

{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// insert after node 
struct Node *insertAfterNode(struct Node *head,struct Node *prevNode,int data)

{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
     ptr -> data = data;
     ptr->next = prevNode->next;
     prevNode->next = ptr;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    // allocate memory for nodes in the linked list iin heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    // link first and second nodes
    head->data = 7;
    head->next = second;

    // link second to third
    second->data = 11;
    second->next = third;

    // link third to forth
    third->data = 41;
    third->next = forth;

    // terminate the linked list at the last node
    forth->data = 66;
    forth->next = NULL;
    printf("linked list before insertion\n");
    linkedListTravesal(head);
    //  head = instertFirst(head,56);
    // head = insertAtIndex(head, 56, 1);
    // head = instertAtEnd(head,57);
    head = insertAfterNode(head,second,45);
    printf("linked list after insertion\n");
    linkedListTravesal(head);
    return 0;
}
