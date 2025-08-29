#include <stdio.h>

int main() {
    double salario, imposto;
    double aliquota, deducao;

    printf("Digite o salario bruto: R$ ");
    scanf("%lf", &salario);

    if (salario <= 2112.00) {
        aliquota = 0.0;
        deducao = 0.0;
    } else if (salario <= 2826.65) {
        aliquota = 0.075;
        deducao = 158.40;
    } else if (salario <= 3751.05) {
        aliquota = 0.15;
        deducao = 370.40;
    } else if (salario <= 4664.68) {
        aliquota = 0.225;
        deducao = 651.73;
    } else {
        aliquota = 0.275;
        deducao = 884.96;
    }

    imposto = salario * aliquota - deducao;
    if (imposto < 0) imposto = 0;

    printf("\nAliquota aplicada: %.1f%%\n", aliquota * 100);
    printf("Imposto de Renda Retido na Fonte: R$ %.2f\n", imposto);

    return 0;
}
