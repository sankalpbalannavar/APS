#include <stdio.h>
#include <stdlib.h>

// Structure of a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a BST with minimal height from a sorted array
struct Node *sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct Node *root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to print the inorder traversal of a BST
void printInorder(struct Node *node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node *root = sortedArrayToBST(arr, 0, n - 1);

    printf("Inorder traversal of the constructed BST:\n");
    printInorder(root);

    return 0;
}