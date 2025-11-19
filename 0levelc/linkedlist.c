#include <stdio.h>
#include <stdlib.h>
// Definition of a singly linked list node

typedef struct Node {
    int value;
    struct Node *next;
} Node;
// Function to insert a new node at the front of the list

Node* list_insert_front(Node *head, int value) {
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = head;
    return n;
}

void list_print(Node *head) {
    while (head) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void list_free(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node *head = NULL;

    head = list_insert_front(head, 10);
    head = list_insert_front(head, 20);
    head = list_insert_front(head, 30);

    list_print(head);
    list_free(head);
    return 0;
}
