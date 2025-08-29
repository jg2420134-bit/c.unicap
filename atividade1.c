#include <stdio.h>

int main() {
    int numero, i, contador = 0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    
    if (numero <= 1) {
        printf("O numero %d NAO eh primo.\n", numero);
        return 0;
    }

    
    for (i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            contador++;
        }
    }

    
    if (contador == 2) {
        printf("O numero %d eh PRIMO.\n", numero);
    } else {
        printf("O numero %d NAO eh primo.\n", numero);
    }

    return 0;
}
