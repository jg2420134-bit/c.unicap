#include <stdio.h>

#define QTD_COLUNAS 10   // usado na Questão 2 (ajuste se quiser)

// ================= QUESTÃO 1 =================

// a) preencher vetor
void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

// b) imprimir vetor
void imprimirVetor(int v[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" }\n");
}

// c) ordenar (bubble sort)
void ordenar(int v[], int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// d) maior número ímpar
void imprimirMaiorImpar(int v[], int n) {
    int maior = 0, achou = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {
            if (!achou || v[i] > maior) {
                maior = v[i];
                achou = 1;
            }
        }
    }

    if (achou)
        printf("Maior ímpar: %d\n", maior);
    else
        printf("Não há números ímpares no vetor\n");
}

// e) vetor de pares e vetor de ímpares
void criarParesImpares(int v[], int n, int pares[], int impares[]) {
    for (int i = 0; i < n; i++) {   // inicializar com 1
        pares[i] = 1;
        impares[i] = 1;
    }

    int p = 0, im = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0)
            pares[p++] = v[i];
        else
            impares[im++] = v[i];
    }
}


// ================= QUESTÃO 2 =================

// a) preencher matriz
void preencherMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas) {
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// b) vetor média das colunas
void preencherVetorMedia(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int v[]) {
    for (int j = 0; j < qtdColunas; j++) {
        int soma = 0;
        for (int i = 0; i < qtdLinhas; i++)
            soma += m[i][j];

        v[j] = soma / qtdLinhas;
    }
}


// ================= PROGRAMA PRINCIPAL =================
int main() {

    // ----- Questão 1 -----
    int n;
    printf("Quantidade de elementos do vetor: ");
    scanf("%d", &n);

    int vetor[n], pares[n], impares[n];

    printf("\n--- PREENCHER VETOR ---\n");
    preencherVetor(vetor, n);

    printf("\n--- VETOR DIGITADO ---\n");
    imprimirVetor(vetor, n);

    printf("\n--- ORDENANDO VETOR ---\n");
    ordenar(vetor, n);
    imprimirVetor(vetor, n);

    printf("\n--- MAIOR IMPAR ---\n");
    imprimirMaiorImpar(vetor, n);

    printf("\n--- CRIANDO VETORES PARES E IMPARES ---\n");
    criarParesImpares(vetor, n, pares, impares);

    printf("Pares: ");
    imprimirVetor(pares, n);

    printf("Impares: ");
    imprimirVetor(impares, n);


    // ----- Questão 2 -----
    int linhas, colunas;
    printf("\n\nQuantidade de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Quantidade de colunas da matriz (máx %d): ", QTD_COLUNAS);
    scanf("%d", &colunas);

    int matriz[linhas][QTD_COLUNAS];
    int medias[colunas];

    printf("\n--- PREENCHER MATRIZ ---\n");
    preencherMatriz(matriz, linhas, colunas);

    printf("\n--- VETOR MÉDIA DAS COLUNAS ---\n");
    preencherVetorMedia(matriz, linhas, colunas, medias);

    imprimirVetor(medias, colunas);

    return 0;
}
