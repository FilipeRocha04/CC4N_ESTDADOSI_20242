#include <stdio.h>  // Biblioteca padrão para funções de entrada e saída, como printf para exibir dados no console.
#include <stdlib.h> // Biblioteca com funções auxiliares, como geração de números aleatórios (rand e srand).
#include <time.h>   // Biblioteca para manipular o tempo, usada aqui para "embaralhar" a geração de números aleatórios.

#define ARRAY_SIZE 50  // Constante que define o tamanho do vetor, facilitando ajustes se necessário.

// Função que implementa o algoritmo Selection Sort para organizar os elementos em ordem crescente.
void selectionSort(int array[], int size) {
    // 'array[]': vetor que contém os números a serem ordenados.
    // 'size': número total de elementos no vetor.
    
    for (int i = 0; i < size - 1; i++) {                // Percorre o vetor até o penúltimo elemento.
        int minIndex = i;                               // Define a posição inicial como a de menor valor.
        
        for (int j = i + 1; j < size; j++) {            // Percorre o vetor à direita de 'i' em busca do menor valor.
            if (array[j] < array[minIndex]) {           // Se encontrar um valor menor que o atual mínimo,
                minIndex = j;                           // atualiza a posição do menor valor encontrado.
            }
        }
        
        // Se o menor valor não está na posição inicial, faz a troca.
        if (minIndex != i) {                            // Verifica se o índice mínimo mudou.
            int temp = array[i];                        // Armazena o valor atual temporariamente.
            array[i] = array[minIndex];                 // Move o menor valor encontrado para a posição 'i'.
            array[minIndex] = temp;                     // Coloca o valor original da posição 'i' na posição de 'minIndex'.
            // A troca foi realizada, posicionando o menor valor na posição correta.
        }
        // Após cada iteração, o menor elemento restante está na posição correta.
    }
}

// Função para preencher o vetor com valores aleatórios entre 0 e 99.
void fillArrayWithRandomValues(int array[], int size) {
    // 'array[]': vetor que será preenchido com valores aleatórios.
    // 'size': o tamanho do vetor, definido pela constante ARRAY_SIZE.

    for (int i = 0; i < size; i++) {                    // Para cada posição do vetor, de 0 a tamanho-1.
        array[i] = rand() % 100;                        // Gera um número aleatório entre 0 e 99 e atribui à posição atual.
        // Cada posição do vetor é preenchida com um número aleatório.
    }
}

// Função para exibir todos os elementos do vetor na tela.
void displayArray(int array[], int size) {
    // 'array[]': vetor que contém os números a serem exibidos.
    // 'size': número de elementos no vetor.

    for (int i = 0; i < size; i++) {                    // Para cada elemento do vetor.
        printf("%d ", array[i]);                        // Exibe o número seguido de um espaço.
    }
    printf("\n");                                       // Quebra de linha após exibir todos os elementos.
    // Todos os elementos do vetor são exibidos em uma linha, seguidos por uma quebra de linha.
}

int main() {
    int array[ARRAY_SIZE];                              // Declara um vetor de inteiros com 50 posições.
    
    srand(time(0));                                     // Inicializa o gerador de números aleatórios com o tempo atual para garantir números variados a cada execução.

    fillArrayWithRandomValues(array, ARRAY_SIZE);       // Preenche o vetor com números aleatórios entre 0 e 99.
    printf("Vetor desordenado:\n");                     // Exibe a mensagem informando que o vetor está desordenado.
    displayArray(array, ARRAY_SIZE);                    // Mostra o vetor desordenado na tela.
    
    selectionSort(array, ARRAY_SIZE);                   // Ordena o vetor usando o algoritmo Selection Sort.
    
    printf("\nVetor ordenado:\n");                      // Exibe a mensagem informando que o vetor está ordenado.
    displayArray(array, ARRAY_SIZE);                    // Mostra o vetor ordenado na tela.

    return 0;                                           // Indica que o programa terminou com sucesso.
}
