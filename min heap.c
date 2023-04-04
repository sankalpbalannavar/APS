#include <stdio.h>
#include <stdlib.h>

struct MinHeap {
    int *arr;
    int capacity;
    int size;
};

struct MinHeap* create_min_heap(int capacity) {
    struct MinHeap* min_heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    min_heap->arr = (int*) malloc(capacity * sizeof(int));
    min_heap->capacity = capacity;
    min_heap->size = 0;
    return min_heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct MinHeap* min_heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < min_heap->size && min_heap->arr[left] < min_heap->arr[smallest])
        smallest = left;

    if (right < min_heap->size && min_heap->arr[right] < min_heap->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&min_heap->arr[i], &min_heap->arr[smallest]);
        min_heapify(min_heap, smallest);
    }
}

void insert(struct MinHeap* min_heap, int key) {
    if (min_heap->size == min_heap->capacity) {
        printf("\nOverflow: Could not insert key\n");
        return;
    }

    min_heap->size++;
    int i = min_heap->size - 1;
    min_heap->arr[i] = key;

    while (i != 0 && min_heap->arr[(i-1)/2] > min_heap->arr[i]) {
        swap(&min_heap->arr[i], &min_heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extract_min(struct MinHeap* min_heap) {
    if (min_heap->size <= 0)
        return -1;
    
    if (min_heap->size == 1) {
        min_heap->size--;
        return min_heap->arr[0];
    }

    int root = min_heap->arr[0];
    min_heap->arr[0] = min_heap->arr[min_heap->size-1];
    min_heap->size--;
    min_heapify(min_heap, 0);

    return root;
}

void print_min_heap(struct MinHeap* min_heap) {
    printf("\nMin Heap:\n");
    for (int i = 0; i < min_heap->size; i++) {
        printf("%d ", min_heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MinHeap* min_heap = create_min_heap(10);
    insert(min_heap, 3);
    insert(min_heap, 2);
    insert(min_heap, 1);
    insert(min_heap, 7);
    insert(min_heap, 8);
    insert(min_heap, 4);
    print_min_heap(min_heap);
    printf("\nExtracted minimum element: %d", extract_min(min_heap));
    printf("\nExtracted minimum element: %d", extract_min(min_heap));
    print_min_heap(min_heap);
    return 0;
}
