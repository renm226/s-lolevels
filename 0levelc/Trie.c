// basic trie in c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;
// Function to create a new trie node
TrieNode* createNode() {
    TrieNode* node = malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}
// Function to insert a word into the trie
void insert(TrieNode* root, const char* word) {
    TrieNode* node = root;
    while (*word) {
        int idx = *word - 'a';
        if (!node->children[idx])
            node->children[idx] = createNode();
        node = node->children[idx];
        word++;
    }
    node->isEndOfWord = true;
}
// Function to search for a word in the trie

bool search(TrieNode* root, const char* word) {
    TrieNode* node = root;
    while (*word) {
        int idx = *word - 'a';
        if (!node->children[idx])
            return false;
        node = node->children[idx];
        word++;
    }
    return node->isEndOfWord;
}
// Function to free the trie

void freeTrie(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            freeTrie(root->children[i]);
    free(root);
}

int main() {
    TrieNode* root = createNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "banana");

    printf("Search 'app': %s\n", search(root, "app") ? "Found" : "Not Found");
    printf("Search 'appl': %s\n", search(root, "appl") ? "Found" : "Not Found");
    printf("Search 'banana': %s\n", search(root, "banana") ? "Found" : "Not Found");

    freeTrie(root);
    return 0;
}
