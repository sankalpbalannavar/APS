// Sankalp Balannavar - 01FE21BCS414
// Title: Inorder Traversal of a Binary Tree

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void inorder_traversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    struct node *root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}