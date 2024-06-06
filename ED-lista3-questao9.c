/*
** Função :  Criar uma função para ordenar elementos de um vetor
** Autor : Luiz Henrique da Silva Ramos
** Data : 02/06
** Observações:
*/

#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j + 1]) {
                (*trocas)++;
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int comparacoes = 0, trocas = 0;

    printf("Vetor original: \n");
    imprimirVetor(vetor, tamanho);

    bubbleSort(vetor, tamanho, &comparacoes, &trocas);

    printf("Vetor ordenado: \n");
    imprimirVetor(vetor, tamanho);

    printf("Numero de comparacoes: %d\n", comparacoes);
    printf("Numero de trocas: %d\n", trocas);

    return 0;
}
