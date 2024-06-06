/*
** Função :vetor em ordem crescente
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Um por um, mover o limite do subvetor não classificado
    for (i = 0; i < n-1; i++) {
        // Encontrar o menor elemento no subvetor não classificado
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Trocar o menor elemento encontrado com o primeiro elemento
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para gerar um vetor com elementos aleatórios
void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
    }
}

// Função para imprimir o vetor
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Inicializar o gerador de números aleatórios
    srand(time(0));

    // Solicitar ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int arr[n];

    // Gerar e imprimir o
