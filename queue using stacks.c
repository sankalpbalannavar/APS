/* 
Title: Queue using Stacks 
Author: Sankalp Balannavar 
SRN: 01FE21BCS414 
*/
#include <stdio.h> 
#include <stdlib.h> 

#define SIZE 5 

struct Stack { 
    int top; 
    int *arr; 
}; 

void push(struct Stack *S, int data) 
{ 
    if (S->top == SIZE - 1) { 
        printf("Stack is Full\n"); 
        return; 
    } 
    S->top++; 
    S->arr[S->top] = data; 
} 

int pop(struct Stack *S) 
{ 
    if (S->top == -1) { 
        printf("Stack is Empty\n"); 
        return -1; 
    } 
    int data = S->arr[S->top]; 
    S->top--; 
    return data; 
} 

void enqueue(struct Stack *S1, int data) 
{ 
    push(S1, data); 
} 

int dequeue(struct Stack *S1, struct Stack *S2) 
{ 
    if (S1->top == -1 && S2->top == -1) { 
        printf("Queue is Empty\n"); 
        return -1; 
    } 

    if (S2->top == -1) { 
        while (S1->top != -1) { 
            int data = pop(S1); 
            push(S2, data); 
        } 
    } 

    return pop(S2); 
} 

int main() 
{ 
    struct Stack S1, S2; 
    S1.top = -1; 
    S2.top = -1; 
    S1.arr = (int*)malloc(sizeof(int) * SIZE); 
    S2.arr = (int*)malloc(sizeof(int) * SIZE); 

    enqueue(&S1, 10); 
    enqueue(&S1, 20); 
    enqueue(&S1, 30); 
    enqueue(&S1, 40); 
    enqueue(&S1, 50); 

    printf("%d\n", dequeue(&S1, &S2)); 
    printf("%d\n", dequeue(&S1, &S2)); 
    printf("%d\n", dequeue(&S1, &S2)); 
    printf("%d\n", dequeue(&S1, &S2)); 
    printf("%d\n", dequeue(&S1, &S2)); 
    printf("%d\n", dequeue(&S1, &S2)); 

    free(S1.arr); 
    free(S2.arr); 
    return 0; 
} 