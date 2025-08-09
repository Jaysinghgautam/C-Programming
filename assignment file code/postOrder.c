#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
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

// Postorder traversal function (User-defined function)
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    // Traverse the left subtree
    postorderTraversal(root->left);
    // Traverse the right subtree
    postorderTraversal(root->right);
    // Visit the root node
    printf("%d ", root->data);
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

    printf("Binary Tree Postorder Traversal\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Postorder Traversal\n");
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
                printf("Postorder Traversal: ");
                postorderTraversal(root);
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
