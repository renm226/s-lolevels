// gcd.c
#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    int a = 36, b = 60;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a,b));
    return 0;
}
