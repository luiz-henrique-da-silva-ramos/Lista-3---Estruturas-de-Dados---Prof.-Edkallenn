/*
** Função : refazer programa anterior
** Autor : Luiz Henrique da Silva Ramos
** Data : 05/06
** Observações:
*/

#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool eh_primo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Função para verificar a Conjectura de Goldbach para um número par
void verificar_goldbach(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (eh_primo(i) && eh_primo(num - i)) {
            printf("%d = %d + %d\n", num, i, num - i);
            return;
        }
    }
    printf("Nenhum par de primos encontrado para %d\n", num);
}

int main() {
    int N;
    printf("Digite um número N: ");
    scanf("%d", &N);

    if (N < 2) {
        printf("N deve ser maior ou igual a 2.\n");
        return 1;
    }

    printf("Verificando a Conjectura de Goldbach para números pares entre 2 e %d:\n", N);
    for (int num = 4; num <= N; num += 2) { // começa em 4 porque 2 é o menor número par, mas não se aplica à conjectura
        verificar_goldbach(num);
    }

    return 0;
}
