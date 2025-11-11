#include <stdio.h>
int height = 200;
int *Ph = &height;

int main()
{
    printf("Height is %d cm\n", height);
    printf("location of height variable: %p\n", &height);
    printf("location stored in pointer Ph: %p\n", Ph);
    printf("Value of height using pointer Ph: %d cm\n", *Ph);
    return 0;
}