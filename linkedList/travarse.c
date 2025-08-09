#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse the linked list
void traverseLinkedList(struct Node* head) {
    struct Node* temp = head;

    // Traverse until the end of the list
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Creating nodes
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Linking nodes
    head->next = second;
    second->next = third;

    // Traverse and display the linked list
    printf("Linked List: ");
    traverseLinkedList(head);

    return 0;
}
 