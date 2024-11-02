#include <stdio.h>  // Biblioteca para funções de entrada e saída
#include <stdlib.h> // Biblioteca para funções auxiliares
#include <time.h>   // Biblioteca para manipular tempo

#define ARRAY_SIZE 50  // Constante que define o tamanho do vetor

// Função que realiza o Bubble Sort para organizar os elementos em ordem crescente.
void bubbleSort(int numbers[], int size) {
    // 'numbers[]': o vetor que contém os números a serem ordenados.
    // 'size': o número total de elementos no vetor.

    for (int pass = 0; pass < size - 1; pass++) {              // Cada passagem percorre o vetor inteiro
        for (int index = 0; index < size - pass - 1; index++) {// Percorre até o último não ordenado
            if (numbers[index] > numbers[index + 1]) {         // Se o número atual é maior que o próximo
                int temp = numbers[index];                     // Armazena o número atual temporariamente
                numbers[index] = numbers[index + 1];           // Move o próximo número para a posição atual
                numbers[index + 1] = temp;                     // Coloca o valor temporário (maior) na posição seguinte
                // A troca foi realizada, movendo o maior número para a posição correta na passagem
            }
        }
        // Ao final de cada passagem, o maior número restante é movido para o final do vetor.
    }
}

// Função para preencher o vetor com valores aleatórios entre 0 e 99.
void fillArrayWithRandomValues(int numbers[], int size) {
    // 'numbers[]': vetor que será preenchido com valores aleatórios.
    // 'size': o tamanho do vetor, definido pela constante ARRAY_SIZE.
    
    for (int i = 0; i < size; i++) {                 // Para cada posição do vetor, de 0 a tamanho-1
        numbers[i] = rand() % 100;                   // Gera um número aleatório entre 0 e 99 e atribui à posição atual
        // Cada posição do vetor é preenchida com um número aleatório
    }
}

// Função para exibir todos os elementos do vetor na tela.
void displayArray(int numbers[], int size) {
    // 'numbers[]': vetor que contém os números a serem exibidos.
    // 'size': número de elementos no vetor.
    
    for (int i = 0; i < size; i++) {                 // Para cada elemento do vetor
        printf("%d ", numbers[i]);                   // Exibe o número seguido de um espaço
    }
    printf("\n");                                    // Quebra de linha após exibir todos os elementos
    // Todos os elementos do vetor são exibidos em uma linha, seguidos por uma quebra de linha.
}

int main() {
    int numbers[ARRAY_SIZE];                         // Declara um vetor de inteiros com 50 posições.
    
    srand(time(0));                                  // Inicializa o gerador de números aleatórios com o tempo atual para garantir números variados a cada execução.
    
    fillArrayWithRandomValues(numbers, ARRAY_SIZE);  // Preenche o vetor com números aleatórios entre 0 e 99.
    printf("Vetor desordenado:\n");                  // Exibe a mensagem informando que o vetor está desordenado.
    displayArray(numbers, ARRAY_SIZE);               // Chama a função para mostrar o vetor desordenado.
    
    bubbleSort(numbers, ARRAY_SIZE);                 // Ordena o vetor usando o algoritmo Bubble Sort.
    
    printf("\nVetor ordenado:\n");                   // Exibe a mensagem informando que o vetor está ordenado.
    displayArray(numbers, ARRAY_SIZE);               // Chama a função para mostrar o vetor ordenado.
    
    return 0;                                        // Indica que o programa terminou com sucesso.
}
