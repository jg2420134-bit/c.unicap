#include <stdio.h>
#include <string.h>

#define QTD_ESTADOS 26

// ======== STRUCT ==========
typedef struct {
    char nome[30];
    int veiculos;
    int acidentes;
} Estado;

// ======== (a) PROCEDIMENTO PARA LER DADOS ==========
void lerDados(Estado estados[]) {
    int i;
    for (i = 0; i < QTD_ESTADOS; i++) {
        printf("\n=== Estado %d ===\n", i + 1);
        printf("Nome do estado: ");
        fflush(stdin);
        fgets(estados[i].nome, 30, stdin);

        // Remove \n do fgets
        estados[i].nome[strcspn(estados[i].nome, "\n")] = '\0';

        printf("Numero de veiculos (2007): ");
        scanf("%d", &estados[i].veiculos);

        printf("Numero de acidentes (2007): ");
        scanf("%d", &estados[i].acidentes);

        getchar(); // limpa buffer
    }
}

// ======== (b) PROCEDIMENTO PARA OBTER MAIOR E MENOR ==========
void maiorMenorAcidentes(Estado estados[], int *indMaior, int *indMenor) {
    int i;
    *indMaior = 0;
    *indMenor = 0;

    for (i = 1; i < QTD_ESTADOS; i++) {
        if (estados[i].acidentes > estados[*indMaior].acidentes) {
            *indMaior = i;
        }
        if (estados[i].acidentes < estados[*indMenor].acidentes) {
            *indMenor = i;
        }
    }
}

// ======== (c) FUNÇÃO PARA PERCENTUAL DE ACIDENTES ==========
float percentual(Estado estados[], int i) {
    if (estados[i].veiculos == 0) return 0;
    return ( (float)estados[i].acidentes / estados[i].veiculos ) * 100.0;
}

// ======== (d) FUNÇÃO PARA MÉDIA DO PAÍS ==========
float mediaAcidentes(Estado estados[]) {
    int soma = 0, i;
    for (i = 0; i < QTD_ESTADOS; i++) {
        soma += estados[i].acidentes;
    }
    return (float)soma / QTD_ESTADOS;
}

// ======== (e) PROCEDIMENTO PARA ESTADOS ACIMA DA MÉDIA ==========
void acimaDaMedia(Estado estados[], float media) {
    int i;
    printf("\n=== Estados acima da média de acidentes ===\n");
    for (i = 0; i < QTD_ESTADOS; i++) {
        if (estados[i].acidentes > media) {
            printf(" - %s (%d acidentes)\n", estados[i].nome, estados[i].acidentes);
        }
    }
}

// ======== PROGRAMA PRINCIPAL ==========
int main() {
    Estado estados[QTD_ESTADOS];
    int indMaior, indMenor;
    float media;
    int i;

    // (a) Ler dados
    lerDados(estados);

    // (b) Maior e menor
    maiorMenorAcidentes(estados, &indMaior, &indMenor);

    printf("\n\n=== (b) MAIOR E MENOR NUMERO DE ACIDENTES ===\n");
    printf("Maior numero de acidentes: %d (%s)\n",
           estados[indMaior].acidentes, estados[indMaior].nome);

    printf("Menor numero de acidentes: %d (%s)\n",
           estados[indMenor].acidentes, estados[indMenor].nome);

    // (c) Percentual em cada estado
    printf("\n=== (c) Percentual de veículos envolvidos em acidentes ===\n");
    for (i = 0; i < QTD_ESTADOS; i++) {
        printf("%s: %.2f%%\n", estados[i].nome, percentual(estados, i));
    }

    // (d) Média do país
    media = mediaAcidentes(estados);
    printf("\n=== (d) Media de acidentes no pais: %.2f ===\n", media);

    // (e) Estados acima da média
    acimaDaMedia(estados, media);

    return 0;
}
