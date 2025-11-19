#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    size_t size;
} Array;

void array_init(Array *arr) {
    arr->size = 0;
}

int array_insert(Array *arr, int value) {
    if (arr->size == MAX_SIZE)
        return 0;  // failure
    arr->data[arr->size++] = value;
    return 1;
}

int array_get(const Array *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return arr->data[index];
}

int main() {
    Array arr;
    array_init(&arr);

    array_insert(&arr, 10);
    array_insert(&arr, 20);
    array_insert(&arr, 30);

    for (size_t i = 0; i < arr.size; i++)
        printf("%d ", array_get(&arr, i));

    return 0;
}
