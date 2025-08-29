#include <stdio.h>

int main() {
    float peso, altura, imc;

    // Entrada de dados
    printf("Digite o seu peso em kg: ");
    scanf("%f", &peso);

    printf("Digite a sua altura em metros: ");
    scanf("%f", &altura);

    // Cálculo do IMC
    imc = peso / (altura * altura);

    // Exibição do resultado
    printf("\nSeu IMC e: %.2f\n", imc);

    // Classificação segundo a OMS
    if (imc < 18.5) {
        printf("Classificacao: Abaixo do peso\n");
    } else if (imc >= 18.5 && imc < 25) {
        printf("Classificacao: Peso normal\n");
    } else if (imc >= 25 && imc < 30) {
        printf("Classificacao: Sobrepeso\n");
    } else if (imc >= 30 && imc < 35) {
        printf("Classificacao: Obesidade grau I\n");
    } else if (imc >= 35 && imc < 40) {
        printf("Classificacao: Obesidade grau II (severa)\n");
    } else {
        printf("Classificacao: Obesidade grau III (morbida)\n");
    }

    return 0;
}
