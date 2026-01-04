//Suffix Array (Simpler Alternative to Suffix Tree)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function to build suffix array
int cmpfunc(const void *a, const void *b, void *str) {
    const char *s = (const char *)str;
    int i1 = *(int *)a;
    int i2 = *(int *)b;
    return strcmp(s + i1, s + i2);
}
// Example usage/main function
int main() {
    char str[] = "banana";
    int n = strlen(str);
    int *suffixArr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        suffixArr[i] = i;

    qsort_r(suffixArr, n, sizeof(int), cmpfunc, str);

    printf("Suffix Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s\n", suffixArr[i], str + suffixArr[i]);

    free(suffixArr);
    return 0;
}