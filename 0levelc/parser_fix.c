// parser_fix.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_and_get(const char *s, size_t idx) {
    if (!s) { fprintf(stderr, "null input\n"); return -1; }
    size_t len = strlen(s);
    if (idx >= len) { fprintf(stderr, "index %zu out of bounds\n", idx); return -1; }
    return (int)s[idx];
}

int main(void) {
    char *buf = malloc(16);
    if (!buf) { fprintf(stderr,"malloc failed\n"); return 1; }
    strcpy(buf,"hello");
    int ch = parse_and_get(buf,2);
    if(ch>=0) printf("char at index 2: %c\n", (char)ch);
    free(buf);
    return 0;
}
