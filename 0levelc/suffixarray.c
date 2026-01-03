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