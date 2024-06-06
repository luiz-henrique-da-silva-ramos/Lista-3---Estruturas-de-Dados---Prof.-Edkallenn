/*
** Função : Conjectura de Goldbach
** Autor : Luiz Henrique da Silva Ramos
** Data : 03/06
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
    printf("Verificando a Conjectura de Goldbach para números pares entre 700 e 1100:\n");
    for (int num = 700; num <= 1100; num += 2) {
        verificar_goldbach(num);
    }
    return 0;
}
