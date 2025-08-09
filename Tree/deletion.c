#include <stdio.h>
#include <stdlib.h>

// Structure for a Node in BST
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find the Inorder Successor (smallest node in the right subtree)
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node from BST
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;

    // Searching for the node to be deleted
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Case 1: Node has no children or only one child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node has two children
        struct Node *temp = findMin(root->right);          // Find inorder successor
        root->data = temp->data;                           // Copy successor's value to current node
        root->right = deleteNode(root->right, temp->data); // Delete the successor
    }
    return root;
}

// Function to perform Inorder Traversal (Left - Root - Right)
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to test deletion in BST
int main()
{
    struct Node *root = NULL;
    int choice, data;

    // Inserting Nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Binary Search Tree (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    // Deleting Nodes
    printf("Enter node to delete: ");
    scanf("%d", &data);
    root = deleteNode(root, data);

    printf("Binary Search Tree after Deletion (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
