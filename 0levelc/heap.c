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