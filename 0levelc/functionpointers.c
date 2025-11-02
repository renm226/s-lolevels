#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int foo(int x, int y) {
    return x + y;
}

void print_if(int x[10], bool (*predicate)(int)) {
    for (int i = 0; i < 10; i++) {
        if (predicate(x[i])) {
            printf("%d\n", x[i]);
        }
    }
}

int compar(const void *x1, const void *x2) {
    return (*(int *)x2 - *(int *)x1);
    
}

int main(void) {

        int x$[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
        for (int i = 0; i < 10; i++)
        printf("%d\n", x$[i]);

        printf("---------------------------------------------\n");

        qsort(x$, 10, sizeof(int), compar);
        for (int i = 0; i < 10; i++)
        printf("%d\n", x$[i]);
        printf("---------------------------------------------\n");

}


