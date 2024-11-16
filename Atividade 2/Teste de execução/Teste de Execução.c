#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função do Shellsort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Função de partição para Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Função do Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para reorganizar o heap (Heapsort)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Função do Heapsort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// Função para gerar arrays aleatórios
void generateRandomArray(int arr[], int n, int max_val) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_val; // Gera números entre 0 e max_val-1
    }
}

// Função para imprimir arrays
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(0)); // Inicializa o gerador de números aleatórios

    const int n = 1000; // Tamanho do array
    const int max_val = 10000; // Valor máximo dos elementos
    int arr[n]; // Array para testes

    // Testando Shellsort
    printf("Testando Shellsort:\n");
    generateRandomArray(arr, n, max_val); // Gera um array aleatório
    clock_t start = clock();
    shellSort(arr, n); // Ordena o array
    clock_t end = clock();
    printf("Tempo Shellsort: %.2f ms\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);

    // Testando Quicksort
    printf("\nTestando Quicksort:\n");
    generateRandomArray(arr, n, max_val); // Gera um novo array aleatório
    start = clock();
    quickSort(arr, 0, n - 1); // Ordena o array
    end = clock();
    printf("Tempo Quicksort: %.2f ms\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);

    // Testando Heapsort
    printf("\nTestando Heapsort:\n");
    generateRandomArray(arr, n, max_val); // Gera um novo array aleatório
    start = clock();
    heapSort(arr, n); // Ordena o array
    end = clock();
    printf("Tempo Heapsort: %.2f ms\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);

    return 0; // Finaliza o programa
}
