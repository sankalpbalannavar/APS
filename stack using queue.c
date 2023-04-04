#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

void enqueue(int data) {
    if (top1 == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    stack1[++top1] = data;
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    int temp = stack2[top2--];
    return temp;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    return 0;
}
