#include <stdio.h>  // Biblioteca padrão para funções de entrada e saída, como printf para exibir dados no console.
#include <stdlib.h> // Biblioteca com funções auxiliares, como geração de números aleatórios (rand e srand).
#include <time.h>   // Biblioteca para manipular o tempo, usada para gerar números aleatórios diferentes em cada execução.

#define ARRAY_SIZE 50  // Constante que define o tamanho do vetor, facilitando alterações futuras.

// Função que implementa o algoritmo Insertion Sort para organizar os elementos em ordem crescente.
void insertionSort(int array[], int size) {
    // 'array[]': vetor que contém os números a serem ordenados.
    // 'size': número total de elementos no vetor.

    for (int i = 1; i < size; i++) {                  // Começa do segundo elemento e percorre até o final.
        int currentElement = array[i];                // Armazena o elemento atual, que será inserido na posição correta.
        int j = i - 1;                                // Inicializa 'j' como o índice anterior ao elemento atual.

        // Move elementos maiores que 'currentElement' uma posição à frente para abrir espaço.
        while (j >= 0 && array[j] > currentElement) { // Enquanto o elemento à esquerda for maior,
            array[j + 1] = array[j];                  // move o elemento para a direita.
            j--;                                      // Continua movendo para a esquerda.
        }
        
        array[j + 1] = currentElement;                // Insere o elemento atual na posição correta.
        // Após essa inserção, a parte do vetor até a posição 'i' está ordenada.
    }
}

// Função para preencher o vetor com valores aleatórios entre 0 e 99.
void fillArrayWithRandomValues(int array[], int size) {
    // 'array[]': vetor que será preenchido com valores aleatórios.
    // 'size': o tamanho do vetor, definido pela constante ARRAY_SIZE.

    for (int i = 0; i < size; i++) {                  // Para cada posição do vetor, de 0 a tamanho-1.
        array[i] = rand() % 100;                      // Gera um número aleatório entre 0 e 99 e atribui à posição atual.
        // Cada posição do vetor é preenchida com um número aleatório.
    }
}

// Função para exibir todos os elementos do vetor na tela.
void displayArray(int array[], int size) {
    // 'array[]': vetor que contém os números a serem exibidos.
    // 'size': número de elementos no vetor.

    for (int i = 0; i < size; i++) {                  // Para cada elemento do vetor.
        printf("%d ", array[i]);                      // Exibe o número seguido de um espaço.
    }
    printf("\n");                                     // Quebra de linha após exibir todos os elementos.
    // Todos os elementos do vetor são exibidos em uma linha, seguidos por uma quebra de linha.
}

int main() {
    int array[ARRAY_SIZE];                            // Declara um vetor de inteiros com 50 posições.

    srand(time(0));                                   // Inicializa o gerador de números aleatórios com o tempo atual para garantir números variados a cada execução.
    
    fillArrayWithRandomValues(array, ARRAY_SIZE);     // Preenche o vetor com números aleatórios entre 0 e 99.
    printf("Vetor desordenado:\n");                   // Exibe a mensagem informando que o vetor está desordenado.
    displayArray(array, ARRAY_SIZE);                  // Mostra o vetor desordenado na tela.
    
    insertionSort(array, ARRAY_SIZE);                 // Ordena o vetor usando o algoritmo Insertion Sort.
    
    printf("\nVetor ordenado:\n");                    // Exibe a mensagem informando que o vetor está ordenado.
    displayArray(array, ARRAY_SIZE);                  // Mostra o vetor ordenado na tela.
    
    return 0;                                         // Indica que o programa terminou com sucesso.
}
