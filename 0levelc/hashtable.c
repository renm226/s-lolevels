#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
// Definition of a hash table node

typedef struct Node {
    char key[50];
    int value;
    struct Node *next;
} Node;
// Definition of the hash table structure
typedef struct {
    Node *buckets[TABLE_SIZE];
} HashTable;
// Simple hash function

unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) h = (h * 31) + *key++;
    return h % TABLE_SIZE;
}
// Function to create a new hash table

HashTable* create_table() {
    HashTable *ht = malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
        ht->buckets[i] = NULL;
    return ht;
}
// Function to insert a key-value pair into the hash table

void insert(HashTable *ht, const char *key, int value) {
    unsigned int idx = hash(key);
    Node *node = malloc(sizeof(Node));
    strcpy(node->key, key);
    node->value = value;
    node->next = ht->buckets[idx];
    ht->buckets[idx] = node;
}
// Function to search for a value by key in the hash table
Node* search(HashTable *ht, const char *key) {
    unsigned int idx = hash(key);
    Node *curr = ht->buckets[idx];
    while (curr) {
        if (strcmp(curr->key, key) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void free_table(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = ht->buckets[i];
        while (curr) {
            Node *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(ht);
}

int main() {
    HashTable *ht = create_table();

    insert(ht, "apple", 10);
    insert(ht, "banana", 20);
    insert(ht, "orange", 30);

    Node *n = search(ht, "banana");
    if (n) printf("Found banana: %d\n", n->value);
    else printf("Banana not found\n");

    free_table(ht);
    return 0;
}
