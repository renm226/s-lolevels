//Binary Min-Heap (Array-Based)
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 50
// Min-Heap structure
typedef struct {
    int data[CAPACITY];
    int size;
} MinHeap;

void heap_init(MinHeap *h) {
    h->size = 0;
}
// Function to insert a new element into the heap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Helper functions for heap operations
void heapify_up(MinHeap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->data[parent] <= h->data[idx])
            break;
        swap(&h->data[parent], &h->data[idx]);
        idx = parent;
    }
}
// Function to remove and return the minimum element from the heap
void heapify_down(MinHeap *h, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < h->size && h->data[left] < h->data[smallest])
            smallest = left;
        if (right < h->size && h->data[right] < h->data[smallest])
            smallest = right;

        if (smallest == idx)
            break;

        swap(&h->data[idx], &h->data[smallest]);
        idx = smallest;
    }
}
// Public API functions
void heap_insert(MinHeap *h, int value) {
    if (h->size == CAPACITY) {
        printf("Heap full\n");
        return;
    }
    h->data[h->size] = value;
    heapify_up(h, h->size);
    h->size++;
}

int heap_extract_min(MinHeap *h) {
    if (h->size == 0) {
        printf("Heap empty\n");
        exit(EXIT_FAILURE);
    }
    int min = h->data[0];
    h->data[0] = h->data[--h->size];
    heapify_down(h, 0);
    return min;
}
// Example usage/main function

int main() {
    MinHeap h;
    heap_init(&h);

    heap_insert(&h, 30);
    heap_insert(&h, 10);
    heap_insert(&h, 20);
    heap_insert(&h, 5);

    while (h.size > 0)
        printf("%d ", heap_extract_min(&h));

    return 0;
}