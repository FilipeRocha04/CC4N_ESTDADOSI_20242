#include <stdio.h> 

// Função do Shellsort
void shellSort(int arr[], int n) {
    // Inicializa o gap (distância entre elementos) como metade do tamanho do array
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Itera pelos elementos do array começando do índice `gap`
        for (int i = gap; i < n; i++) {
            int temp = arr[i]; // Armazena o valor do elemento atual
            int j;
            // Move os elementos maiores que `temp` para frente, seguindo o intervalo `gap`
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap]; // Move o elemento maior para a posição atual
            }
            arr[j] = temp; // Insere o valor armazenado na posição correta
        }
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
    int arr[] = {12, 34, 54, 2, 3}; // Define o array inicial
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Original: ");
    printArray(arr, n); // Imprime o array antes da ordenação

    shellSort(arr, n); // Chama a função Shellsort para ordenar o array

    printf("Ordenada: ");
    printArray(arr, n); // Imprime o array após a ordenação

    return 0; // Indica que o programa terminou com sucesso
}
