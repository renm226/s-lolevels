//implementation of stack using arrays
#include <stdio.h>
#include <stdlib.h>

#define STACK_CAPACITY 50


// Definition of a stack structure
typedef struct {
    int data[STACK_CAPACITY];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

int stack_push(Stack *s, int value) {
    if (s->top == STACK_CAPACITY - 1)
        return 0; // overflow
    s->data[++s->top] = value;
    return 1;
}

int stack_pop(Stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    stack_init(&s);

    stack_push(&s, 10);
    stack_push(&s, 20);
    stack_push(&s, 30);

    printf("%d\n", stack_pop(&s));
    printf("%d\n", stack_pop(&s));
    printf("%d\n", stack_pop(&s));

    return 0;
}
