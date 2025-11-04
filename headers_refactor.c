// headers_refactor.c
#include <stdio.h>
#include "headers_refactor.h"

void helper_print(const char *s) {
    if (s) {
        printf("Helper: %s\n", s);
    } else {
        printf("Helper: (null)\n");
    }
}

#ifdef BUILD_MAIN
int main(void) {
    helper_print("Header refactor integrated");
    return 0;
}
#endif
