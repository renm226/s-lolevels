//Red-Black Tree (Simplified Insert Example)
#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int key;
    Color color;
    struct Node *left, *right, *parent;
} Node;
// Function to create a new Red-Black tree node
Node* newNode(int key) {
    Node* n = malloc(sizeof(Node));
    n->key = key;
    n->color = RED;
    n->left = n->right = n->parent = NULL;
    return n;
}

// Example: left rotate utility
Node* leftRotate(Node* root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
    return root;
}

// Simplified insert (without full fix-up)
Node* insertBST(Node* root, Node* n) {
    if (!root) return n;
    if (n->key < root->key) {
        root->left = insertBST(root->left, n);
        root->left->parent = root;
    } else if (n->key > root->key) {
        root->right = insertBST(root->right, n);
        root->right->parent = root;
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d(%s) ", root->key, root->color == RED ? "R" : "B");
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    int keys[] = {10, 20, 30, 15, 25};
    for (int i = 0; i < 5; i++)
        root = insertBST(root, newNode(keys[i]));

    printf("Inorder traversal of Red-Black tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
