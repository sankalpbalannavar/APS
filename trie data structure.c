// Author: Sankalp Balannavar
// SRN: 01FE21BCS414
// Title: Trie Data Structure Implementation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHILDREN 26

typedef struct trie_node {
    bool is_end;
    struct trie_node* children[MAX_CHILDREN];
} TrieNode;

TrieNode* new_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_end = false;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = new_node();
        }
        curr = curr->children[index];
    }
    curr->is_end = true;
}

bool search(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr != NULL && curr->is_end;
}

int main() {
    TrieNode* root = new_node();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "hi");
    insert(root, "how");
    insert(root, "are");
    insert(root, "you");

    printf("%s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("%s\n", search(root, "world") ? "Found" : "Not Found");
    printf("%s\n", search(root, "hi") ? "Found" : "Not Found");
    printf("%s\n", search(root, "how") ? "Found" : "Not Found");
    printf("%s\n", search(root, "are") ? "Found" : "Not Found");
    printf("%s\n", search(root, "you") ? "Found" : "Not Found");
    printf("%s\n", search(root, "hola") ? "Found" : "Not Found");

    return 0;
}