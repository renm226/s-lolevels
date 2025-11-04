// parser_fix.c
// Example program that demonstrates and fixes a common segfault cause:
// checking malloc return and validating index bounds before dereference.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_and_get(const char *s, size_t idx) {
    if (!s) {
        fprintf(stderr, "parse_and_get: null input\n");
        return -1;
    }

    size_t len = strlen(s);
    // protect against out-of-bounds access
    if (idx >= len) {
        fprintf(stderr, "parse_and_get: index %zu out of bounds (len=%zu)\n", idx, len);
        return -1;
    }

    // safe access
    return (int)s[idx];
}

int main(void) {
    // simulate parsed buffer that could be NULL if allocation failed
    char *buf = malloc(16);
    if (buf == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    strcpy(buf, "hello"); // within allocated size

    // safe usage: check return and bounds before using value
    int ch = parse_and_get(buf, 2);
    if (ch >= 0) {
        printf("char at index 2: '%c' (code %d)\n", (char)ch, ch);
    } else {
        fprintf(stderr, "failed to get char\n");
    }

    free(buf);
    return 0;
}
