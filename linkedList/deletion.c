#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and display the linked list
void traverseLinkedList(struct Node *head)
{
    struct Node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the beginning
struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a specific position
struct Node *deleteFromPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty! Nothing to delete.\n");
        return NULL;
    }

    if (position == 1)
    {
        return deleteFromBeginning(head);
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position! Node not deleted.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to insert a node at the end (for initial list creation)
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    // Creating an initial linked list for testing
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = insertAtEnd(head, 50);

    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = deleteFromBeginning(head);
            break;
        case 2:
            head = deleteFromEnd(head);
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            head = deleteFromPosition(head, position);
            break;
        case 4:
            traverseLinkedList(head);
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
