// Simple hashtable implementation in C with linear probing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definition of hashtable size
#define TABLE_SIZE 10
// Definition of a hash table entry
typedef struct {
    char key[50];
    int value;
    int used; // 0 = empty, 1 = used
} HashEntry;
// Definition of the hash table structure
typedef struct {
    HashEntry table[TABLE_SIZE];
} HashTable;
// Simple hash function
unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) h = (h * 31) + *key++;
    return h % TABLE_SIZE;
}
//  Function to insert a key-value pair into the hash table
void insert(HashTable *ht, const char *key, int value) {
    unsigned int idx = hash(key);
    unsigned int start = idx;
    while (ht->table[idx].used) {
        if (strcmp(ht->table[idx].key, key) == 0) {
            ht->table[idx].value = value; // update
            return;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) { printf("Table full\n"); return; }
    }
    strcpy(ht->table[idx].key, key);
    ht->table[idx].value = value;
    ht->table[idx].used = 1;
}
// Function to search for a value by key in the hash table
HashEntry* search(HashTable *ht, const char *key) {
    unsigned int idx = hash(key);
    unsigned int start = idx;
    while (ht->table[idx].used) {
        if (strcmp(ht->table[idx].key, key) == 0)
            return &ht->table[idx];
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == start) break;
    }
    return NULL;
}

int main() {
    HashTable ht = {0};

    insert(&ht, "apple", 10);
    insert(&ht, "banana", 20);
    insert(&ht, "orange", 30);

    HashEntry *e = search(&ht, "orange");
    if (e) printf("Found orange: %d\n", e->value);
    else printf("Orange not found\n");

    return 0;
}
