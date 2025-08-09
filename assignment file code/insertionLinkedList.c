#include <stdio.h>
#include <stdlib.h>

 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder traversal function (User-defined function)
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    // Visit the root node
    printf("%d ", root->data);
    // Traverse the left subtree
    preorderTraversal(root->left);
    // Traverse the right subtree
    preorderTraversal(root->right);
}

// Function to insert nodes in the tree (for demonstration)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;

    printf("Binary Tree Preorder Traversal\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
