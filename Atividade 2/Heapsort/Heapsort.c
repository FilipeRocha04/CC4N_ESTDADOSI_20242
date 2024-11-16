#include <stdio.h> 

// Função para reorganizar o heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Inicializa o maior elemento como a raiz
    int left = 2 * i + 1; // Calcula o índice do filho esquerdo
    int right = 2 * i + 2; // Calcula o índice do filho direito

    // Verifica se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Verifica se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Se o maior não for a raiz, troca os valores
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Continua reorganizando o subárvore afetada
        heapify(arr, n, largest);
    }
}

// Função do Heapsort
void heapSort(int arr[], int n) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify na árvore reduzida
        heapify(arr, i, 0);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    // Itera por cada elemento do array e imprime
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n"); // Adiciona uma nova linha após imprimir o array
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Define o array inicial
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Original: ");
    printArray(arr, n); // Imprime o array antes da ordenação

    heapSort(arr, n); // Chama o Heapsort para ordenar o array

    printf("Ordenada: ");
    printArray(arr, n); // Imprime o array após a ordenação

    return 0; // Indica que o programa terminou com sucesso
}
