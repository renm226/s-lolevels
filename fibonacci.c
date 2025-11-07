// fibonacci.c
#include <stdio.h>

int main(void) {
    int n = 10;
    int a = 0, b = 1;
    printf("Fibonacci series: ");
    for(int i=0;i<n;i++){
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
    return 0;
}
