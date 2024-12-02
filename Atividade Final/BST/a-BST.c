#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;


Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}


Node* bstInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key)
        root->left = bstInsert(root->left, key);
    else
        root->right = bstInsert(root->right, key);
    return root;
}


void printTree(Node* root, int space) {
    if (root == NULL) return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    printTree(root->left, space);
}

int main() {
    int values[] = {15, 10, 20, 8, 12, 17, 25, 7, 1, 13};
    int n = sizeof(values) / sizeof(values[0]);
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        printf("\nInserindo %d na BST:\n", values[i]);
        root = bstInsert(root, values[i]);
        printTree(root, 0);
    }

    return 0;
}
