#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

void linkedListTravesal (struct Node *ptr) {
    while(ptr != NULL) {
printf("element :%d\n",ptr ->data);
ptr = ptr -> next;
    }
}

int main () {
    struct Node * head;
    struct Node * second;
    struct Node * third;
    
    // allocate memory for nodes in the linked list iin heap
    head = (struct Node * )malloc(sizeof(struct Node));
    second = (struct Node * )malloc(sizeof(struct Node)); 
    third = (struct Node * )malloc(sizeof(struct Node)); 

    // link first and second nodes 
    head -> data = 7;
    head -> next = second;

    // linke second to third 
    second -> data = 11;
    second -> next = third;

    //terminate the linked list at the third node
    third -> data = 66;
    third -> next = NULL;
linkedListTravesal(head);

    return 0;
    
    
}