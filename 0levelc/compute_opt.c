// Simple example: precompute value then print - avoids redundant computation.

#include <stdio.h>

int main(void) {
    int n = 10;
    for (int i = 0; i < n; ++i) {
        int sq = i * i;      // compute once per iteration
        printf("%d ", sq);
    }
    printf("\n");
    return 0;
}
