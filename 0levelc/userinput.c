#include <stdio.h>

int main(void) {
    double a, b, c;
    printf("Enter 3 numbers: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        puts("Input error");
        return 1;
    }
    printf("Sum: %g\n", a + b + c);
    return 0;
}
