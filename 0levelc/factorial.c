// factorial.c
#include <stdio.h>

unsigned long factorial(unsigned int n) {
    unsigned long result = 1;
    for(unsigned int i=2;i<=n;i++)
        result *= i;
    return result;
}

int main(void) {
    unsigned int n = 5;
    printf("Factorial of %u is %lu\n", n, factorial(n));
    return 0;
}
