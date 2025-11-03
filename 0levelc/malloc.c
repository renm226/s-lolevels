//memory manipulation techniques
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
int main() {
    char *str1 = "Hello, World!";
    //allocate memory for str2
    char *str2 = (char *)malloc(strlen(str1) + 1); // +1 for null terminator
    if (str2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    //copy str1 to str2
    strcpy(str2, str1);
    printf("Copied string: %s\n", str2);
    //free allocated memory
    free(str2);
    return 0;
}   
