//memory manipulation functions
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for an array of 10 integers
    int *arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i; // Store square of index
    }

    // Print the array
    printf("Array elements:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory to hold 20 integers
    int *new_arr = (int *)realloc(arr, 20 * sizeof(int));
    if (new_arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr); // Free original memory if realloc fails
        return 1;
    }
    arr = new_arr;

    // Initialize the new elements
    for (int i = 10; i < 20; i++) {
        arr[i] = i * i; // Store square of index
    }

    // Print the resized array
    printf("Resized array elements:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    return 0;
}