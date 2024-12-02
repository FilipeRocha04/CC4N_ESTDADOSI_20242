#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// Função para criar um novo nó
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Função para inserir um nó na BST
Node* bstInsert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key)
        root->left = bstInsert(root->left, key);
    else
        root->right = bstInsert(root->right, key);
    return root;
}

// Função para encontrar o nó de menor valor
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Função para remover um nó da BST
Node* bstRemove(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = bstRemove(root->left, key);
    else if (key > root->key)
        root->right = bstRemove(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = bstRemove(root->right, temp->key);
    }

    return root;
}

// Função para imprimir a árvore em formato hierárquico
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
    int initialValues[] = {15, 10, 20, 8, 12, 17, 25, 7, 1, 13, 30};
    int n = sizeof(initialValues) / sizeof(initialValues[0]);
    Node* root = NULL;

    // Inserindo os valores iniciais
    printf("=== Construção inicial da BST ===\n");
    for (int i = 0; i < n; i++) {
        printf("\nInserindo %d na BST:\n", initialValues[i]);
        root = bstInsert(root, initialValues[i]);
        printTree(root, 0);
    }

    // Removendo o nó 30
    printf("\n=== Removendo o nó 30 da BST ===\n");
    root = bstRemove(root, 30);
    printTree(root, 0);

    return 0;
}
