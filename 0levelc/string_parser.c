#include <stdio.h>
#include <string.h>

void parse_string(const char *s) {
    if (!s) { printf("null input\n"); return; }
    for(size_t i=0;i<strlen(s);i++){
        printf("char %zu: %c\n", i, s[i]);
    }
}

int main(void) {
    parse_string("hello");
    return 0;
}
