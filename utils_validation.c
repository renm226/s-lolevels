// utils_validation.c
// Demonstrates robust input validation (checks scanf return and bounds).

#include <stdio.h>

int main(void) {
    int x;
    printf("Please enter a non-negative integer: ");
    if (scanf("%d", &x) != 1) {
        fprintf(stderr, "error: invalid input\n");
        return 2;
    }
    if (x < 0) {
        fprintf(stderr, "error: negative value not allowed\n");
        return 3;
    }
    printf("You entered: %d\n", x);
    return 0;
}
