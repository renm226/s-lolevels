//a circular array-based queue implementation in C
#include <stdio.h>
#include <stdlib.h>
// Define  queue structure
#define QUEUE_CAPACITY 50

typedef struct {
    int data[QUEUE_CAPACITY];
    int front, rear, size;
} Queue;
// Function to initialize the queue

void queue_init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to add an element to the queue
int enqueue(Queue *q, int value) {
    if (q->size == QUEUE_CAPACITY)
        return 0; // full

    q->rear = (q->rear + 1) % QUEUE_CAPACITY;
    q->data[q->rear] = value;
    q->size++;
    return 1;
}
// Function to remove an element from the queue

int dequeue(Queue *q) {
    if (q->size == 0) {
        fprintf(stderr, "Queue underflow\n");
        exit(EXIT_FAILURE);
    }

    
    int value = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_CAPACITY;
    q->size--;
    return value;
}

// Example usage/main function
int main() {
    Queue q;
    queue_init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    return 0;
}
