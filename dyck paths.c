/*
 * C program to generate all possible Dyck paths of length n
 * Author: Sankalp Balannavar
 * SRN: 01FE21BCS414
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Stack data structure
typedef struct {
    int top;
    int items[MAX_LENGTH];
} Stack;

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(Stack* stack, int item) {
    if (stack->top == MAX_LENGTH - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to print a Dyck path given its parentheses string representation
void printDyckPath(char* path, int length) {
    Stack* stack = createStack();
    int i;
    for (i = 0; i < length; i++) {
        if (path[i] == '(') {
            push(stack, i);
        } else {
            int start = pop(stack);
            printf("%d %d\n", start, i);
        }
    }
    free(stack);
}

// Function to generate all possible Dyck paths of length n
void generateDyckPaths(int n, char* path, int index, int open, int close) {
    if (index == 2 * n) {
        printDyckPath(path, 2 * n);
        return;
    }
    if (open < n) {
        path[index] = '(';
        generateDyckPaths(n, path, index + 1, open + 1, close);
    }
    if (close < open) {
        path[index] = ')';
        generateDyckPaths(n, path, index + 1, open, close + 1);
    }
}

// Main function
int main() {
    int n = 3; // length of Dyck paths
    char path[2 * MAX_LENGTH];
    generateDyckPaths(n, path, 0, 0, 0);
    return 0;
}