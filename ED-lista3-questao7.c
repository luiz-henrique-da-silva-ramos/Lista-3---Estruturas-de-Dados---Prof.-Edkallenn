/*
** Função : quicksort
** Autor : Luiz Henrique da Silva Ramos
** Data : 03/06
** Observações:
*/

#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quicksort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, pi - 1);
        quicksort(vetor, pi + 1, fim);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("Vetor original: \n");
    imprimirVetor(vetor, tamanho);
    quicksort(vetor, 0, tamanho - 1);
    printf("Vetor ordenado: \n");
    imprimirVetor(vetor, tamanho);
    return 0;
}
