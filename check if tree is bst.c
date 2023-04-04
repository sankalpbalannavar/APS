#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to check if a given binary tree is a BST or not
bool isBST(struct Node *root) {
    static struct Node *prev = NULL;

    if (root) {
        if (!isBST(root->left))
            return false;
        if (prev != NULL && root->data <= prev->data)
            return false;
        prev = root;
        return isBST(root->right);
    }

    return true;
}

int main() {
    /* Let's create a binary tree that is not a BST
             3
            / \
           2   5
          / \
         1   4
    */
    struct Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    if (isBST(root))
        printf("The given binary tree is a BST");
    else
        printf("The given binary tree is not a BST");

    return 0;
}