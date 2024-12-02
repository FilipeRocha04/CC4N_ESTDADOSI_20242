#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
    int height;
} Node;


Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}


int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}


Node* avlInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->key)
        root->left = avlInsert(root->left, key);
    else if (key > root->key)
        root->right = avlInsert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key)
        return rotateRight(root);
    if (balance < -1 && key > root->right->key)
        return rotateLeft(root);
    if (balance > 1 && key > root->left->key) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && key < root->right->key) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

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
    int initialValues[] = {15, 10, 20, 8, 12, 17, 25, 7, 1, 13};
    int newValues[] = {21, 18, 2, 11, 25, 30};
    int n1 = sizeof(initialValues) / sizeof(initialValues[0]);
    int n2 = sizeof(newValues) / sizeof(newValues[0]);
    Node* root = NULL;

    printf("=== Construção inicial da AVL ===\n");
    for (int i = 0; i < n1; i++) {
        printf("\nInserindo %d na AVL:\n", initialValues[i]);
        root = avlInsert(root, initialValues[i]);
        printTree(root, 0);
    }

    printf("\n=== Inserindo novos valores na AVL ===\n");
    for (int i = 0; i < n2; i++) {
        printf("\nInserindo %d na AVL:\n", newValues[i]);
        root = avlInsert(root, newValues[i]);
        printTree(root, 0);
    }

    return 0;
}
