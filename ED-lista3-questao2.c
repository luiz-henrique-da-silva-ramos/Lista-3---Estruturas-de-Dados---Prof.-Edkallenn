/*
** Função : Registro
** Autor : Luiz Henrique da Silva Ramos
** Data : 03/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    char data_nascimento[11]; // formato "dd/mm/yyyy"
    char rg[15];
    char data_admissao[11]; // formato "dd/mm/yyyy"
    float salario;
} Empregado;

void ler_empregado(Empregado *emp) {
    printf("Nome: ");
    scanf(" %[^\n]", emp->nome);
    printf("Data de nascimento (dd/mm/yyyy): ");
    scanf(" %s", emp->data_nascimento);
    printf("RG: ");
    scanf(" %s", emp->rg);
    printf("Data de admissão (dd/mm/yyyy): ");
    scanf(" %s", emp->data_admissao);
    printf("Salário: ");
    scanf("%f", &emp->salario);
}

void escrever_empregado(const Empregado *emp) {
    printf("\nNome: %s\n", emp->nome);
    printf("Data de nascimento: %s\n", emp->data_nascimento);
    printf("RG: %s\n", emp->rg);
    printf("Data de admissão: %s\n", emp->data_admissao);
    printf("Salário: %.2f\n", emp->salario);
}

void excluir_empregado(Empregado *emp) {
    strcpy(emp->nome, "");
    strcpy(emp->data_nascimento, "");
    strcpy(emp->rg, "");
    strcpy(emp->data_admissao, "");
    emp->salario = 0.0;
}

int main() {
    int num_empregados;
    printf("Digite o número de empregados: ");
    scanf("%d", &num_empregados);

    // Alocação dinâmica do vetor de empregados
    Empregado *empregados = (Empregado *)malloc(num_empregados * sizeof(Empregado));
    if (empregados == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Ler dados dos empregados
    for (int i = 0; i < num_empregados; i++) {
        printf("\nEmpregado %d\n", i + 1);
        ler_empregado(&empregados[i]);
    }

    // Escrever dados dos empregados
    printf("\n--- Lista de Empregados ---\n");
    for (int i = 0; i < num_empregados; i++) {
        printf("\nEmpregado %d\n", i + 1);
        escrever_empregado(&empregados[i]);
    }

    // Exemplo de exclusão de um empregado (excluindo o primeiro empregado)
    excluir_empregado(&empregados[0]);
    printf("\n--- Lista de Empregados após exclusão do primeiro empregado ---\n");
    for (int i = 0; i < num_empregados; i++) {
        printf("\nEmpregado %d\n", i + 1);
        escrever_empregado(&empregados[i]);
    }

    // Liberação da memória alocada
    free(empregados);

    return 0;
}
