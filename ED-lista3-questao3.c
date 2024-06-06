/*
** Função : vetor de ponteiros
** Autor : Luiz Henrique da Silva Ramos
** Data : 03/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Aeroporto
typedef struct {
    char sigla[4]; // 3 caracteres + '\0'
    char cidade[51]; // 50 caracteres + '\0'
    char pais[31]; // 30 caracteres + '\0'
    float taxa;
    int capacidade;
} Aeroporto;

// Função para ler os dados de um aeroporto
void ler_aeroporto(Aeroporto *aero) {
    printf("Sigla: ");
    scanf(" %3s", aero->sigla);
    printf("Cidade: ");
    scanf(" %50s", aero->cidade);
    printf("Pais: ");
    scanf(" %30s", aero->pais);
    printf("Taxa: ");
    scanf("%f", &aero->taxa);
    printf("Capacidade: ");
    scanf("%d", &aero->capacidade);
}

// Função para escrever os dados de um aeroporto
void escrever_aeroporto(const Aeroporto *aero) {
    printf("\nSigla: %s\n", aero->sigla);
    printf("Cidade: %s\n", aero->cidade);
    printf("Pais: %s\n", aero->pais);
    printf("Taxa: %.2f\n", aero->taxa);
    printf("Capacidade: %d\n", aero->capacidade);
}

// Função para excluir um aeroporto (libera memória e define ponteiro como NULL)
void excluir_aeroporto(Aeroporto **aero) {
    if (*aero != NULL) {
        free(*aero);
        *aero = NULL;
    }
}

int main() {
    int num_aeroportos;
    printf("Digite o número de aeroportos: ");
    scanf("%d", &num_aeroportos);

    // Alocação dinâmica do vetor de ponteiros para Aeroporto
    Aeroporto **aeroportos = (Aeroporto **)malloc(num_aeroportos * sizeof(Aeroporto *));
    if (aeroportos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Inicializa o vetor de ponteiros
    for (int i = 0; i < num_aeroportos; i++) {
        aeroportos[i] = NULL;
    }

    // Ler dados dos aeroportos
    for (int i = 0; i < num_aeroportos; i++) {
        aeroportos[i] = (Aeroporto *)malloc(sizeof(Aeroporto));
        if (aeroportos[i] == NULL) {
            printf("Erro na alocação de memória.\n");
            return 1;
        }
        printf("\nAeroporto %d\n", i + 1);
        ler_aeroporto(aeroportos[i]);
    }

    // Escrever dados dos aeroportos
    printf("\n--- Lista de Aeroportos ---\n");
    for (int i = 0; i < num_aeroportos; i++) {
        printf("\nAeroporto %d\n", i + 1);
        escrever_aeroporto(aeroportos[i]);
    }

    // Exemplo de exclusão de um aeroporto (excluindo o primeiro aeroporto)
    excluir_aeroporto(&aeroportos[0]);
    printf("\n--- Lista de Aeroportos após exclusão do primeiro aeroporto ---\n");
    for (int i = 0; i < num_aeroportos; i++) {
        if (aeroportos[i] != NULL) {
            printf("\nAeroporto %d\n", i + 1);
            escrever_aeroporto(aeroportos[i]);
        } else {
            printf("\nAeroporto %d foi excluído.\n", i + 1);
        }
    }

    // Liberação da memória alocada
    for (int i = 0; i < num_aeroportos; i++) {
        excluir_aeroporto(&aeroportos[i]);
    }
    free(aeroportos);

    return 0;
}
