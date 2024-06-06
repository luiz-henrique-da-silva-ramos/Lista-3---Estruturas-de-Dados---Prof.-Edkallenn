/*
** Função : complexo
** Autor : Luiz Henrique da Silva Ramos
** Data : 02/06
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complexo;

Complexo *criarComplexo(double real, double imag) {
    Complexo *num = (Complexo *)malloc(sizeof(Complexo));
    if (num != NULL) {
        num->real = real;
        num->imag = imag;
    }
    return num;
}

void destruirComplexo(Complexo *num) {
    free(num);
}

Complexo *lerComplexo() {
    double real, imag;
    printf("Digite a parte real: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginaria: ");
    scanf("%lf", &imag);
    return criarComplexo(real, imag);
}

Complexo *somarComplexos(Complexo *num1, Complexo *num2) {
    return criarComplexo(num1->real + num2->real, num1->imag + num2->imag);
}

Complexo *subtrairComplexos(Complexo *num1, Complexo *num2) {
    return criarComplexo(num1->real - num2->real, num1->imag - num2->imag);
}

Complexo *multiplicarComplexos(Complexo *num1, Complexo *num2) {
    return criarComplexo(num1->real * num2->real - num1->imag * num2->imag,
                          num1->real * num2->imag + num1->imag * num2->real);
}

Complexo *dividirComplexos(Complexo *num1, Complexo *num2) {
    double divisor = num2->real * num2->real + num2->imag * num2->imag;
    return criarComplexo((num1->real * num2->real + num1->imag * num2->imag) / divisor,
                          (num1->imag * num2->real - num1->real * num2->imag) / divisor);
}

void mostrarComplexo(Complexo *num) {
    printf("(%f, %f)\n", num->real, num->imag);
}

int main() {
    Complexo *num1 = lerComplexo();
    Complexo *num2 = lerComplexo();

    Complexo *soma = somarComplexos(num1, num2);
    Complexo *subtracao = subtrairComplexos(num1, num2);
    Complexo *multiplicacao = multiplicarComplexos(num1, num2);
    Complexo *divisao = dividirComplexos(num1, num2);

    printf("Soma: ");
    mostrarComplexo(soma);
    printf("Subtracao: ");
    mostrarComplexo(subtracao);
    printf("Multiplicacao: ");
    mostrarComplexo(multiplicacao);
    printf("Divisao: ");
    mostrarComplexo(divisao);

    destruirComplexo(num1);
    destruirComplexo(num2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}
