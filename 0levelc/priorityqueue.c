
// A simple priority queue implementation in C using a binary heap.
#include <stdio.h>
#include <stdlib.h>
// Define maximum number of tasks
#define MAX_TASKS 50
// Task structure
typedef struct {
    int priority;
    int task_id;
} Task;
//
typedef struct {
    Task heap[MAX_TASKS];
    int size;
} PriorityQueue;

void pq_init(PriorityQueue *pq) {
    pq->size = 0;
}

void swap(Task *a, Task *b) {
    Task t = *a;
    *a = *b;
    *b = t;
}
// Helper functions for heap operations
void heapify_up(PriorityQueue *pq, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (pq->heap[parent].priority <= pq->heap[idx].priority)
            break;
        swap(&pq->heap[parent], &pq->heap[idx]);
        idx = parent;
    }
}
// Function to remove and return the highest priority task from the queue
void heapify_down(PriorityQueue *pq, int idx) {
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < pq->size &&
            pq->heap[left].priority < pq->heap[smallest].priority)
            smallest = left;

        if (right < pq->size &&
            pq->heap[right].priority < pq->heap[smallest].priority)
            smallest = right;

        if (smallest == idx)
            break;

        swap(&pq->heap[idx], &pq->heap[smallest]);
        idx = smallest;
    }
}
// Public API functions
void pq_push(PriorityQueue *pq, int task_id, int priority) {
    if (pq->size == MAX_TASKS) return;

    pq->heap[pq->size] = (Task){priority, task_id};
    heapify_up(pq, pq->size);
    pq->size++;
}

Task pq_pop(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Queue empty\n");
        exit(EXIT_FAILURE);
    }
    Task t = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapify_down(pq, 0);
    return t;
}
// Example usage/main function
int main() {
    PriorityQueue pq;
    pq_init(&pq);

    pq_push(&pq, 1, 3);
    pq_push(&pq, 2, 1);
    pq_push(&pq, 3, 2);

    while (pq.size > 0) {
        Task t = pq_pop(&pq);
        printf("Task %d with priority %d\n", t.task_id, t.priority);
    }
    return 0;
}
