#include <stdio.h> // Inclui a biblioteca padrão para entrada e saída

// Função de partição
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Define o pivô como o último elemento do array
    int i = (low - 1); // Inicializa o índice para elementos menores que o pivô

    // Itera pelos elementos do array para posicionar o pivô corretamente
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // Verifica se o elemento atual é menor que o pivô
            i++; // Incrementa o índice dos elementos menores
            // Troca o elemento atual com o elemento em `i`
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Coloca o pivô na posição correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1); // Retorna a posição final do pivô
}

// Função do Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) { // Verifica se há mais de um elemento para ordenar
        int pi = partition(arr, low, high); // Particiona o array e obtém a posição do pivô
        quickSort(arr, low, pi - 1); // Ordena os elementos antes do pivô
        quickSort(arr, pi + 1, high); // Ordena os elementos após o pivô
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
    int arr[] = {10, 7, 8, 9, 1, 5}; // Define o array inicial
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Original: ");
    printArray(arr, n); // Imprime o array antes da ordenação

    quickSort(arr, 0, n - 1); // Chama o Quicksort para ordenar o array

    printf("Ordenada: ");
    printArray(arr, n); // Imprime o array após a ordenação

    return 0; // Indica que o programa terminou com sucesso
}
