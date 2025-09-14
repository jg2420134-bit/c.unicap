#include <stdio.h>

#define MAX 50

void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void removerElemento(int vetor[], int *tamanho, int valor) {
    int pos = buscaBinaria(vetor, *tamanho, valor);
    if (pos == -1) {
        printf("Elemento não encontrado.\n");
        return;
    }
    for (int i = pos; i < (*tamanho) - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("Elemento removido com sucesso.\n");
}

int main() {
    int vetor[MAX];
    int tamanho_max, tamanho = 0;

    // Tamanho do vetor
    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho_max);
    } while (tamanho_max < 3 || tamanho_max > 50);

    int qtd;
    printf("Quantos valores deseja inserir (máximo %d)? ", tamanho_max);
    scanf("%d", &qtd);

    if (qtd > tamanho_max) qtd = tamanho_max;

    printf("Digite os valores (inserção ordenada):\n");
    for (int i = 0; i < qtd; i++) {
        int valor;
        scanf("%d", &valor);
        inserirOrdenado(vetor, &tamanho, valor);
    }

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Imprimir todo o vetor\n");
        printf("2. Consultar (posição de um elemento)\n");
        printf("3. Remover um elemento\n");
        printf("4. Inserir um valor\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;
            case 2: {
                int val;
                printf("Digite o valor para buscar: ");
                scanf("%d", &val);
                int pos = buscaBinaria(vetor, tamanho, val);
                if (pos != -1)
                    printf("Elemento encontrado na posição %d.\n", pos);
                else
                    printf("Elemento não encontrado (-1).\n");
                break;
            }
            case 3: {
                int val;
                printf("Digite o valor para remover: ");
                scanf("%d", &val);
                removerElemento(vetor, &tamanho, val);
                break;
            }
            case 4: {
                if (tamanho >= tamanho_max) {
                    printf("Vetor cheio! Não é possível inserir mais elementos.\n");
                    break;
                }
                int val;
                printf("Digite o valor para inserir: ");
                scanf("%d", &val);
                inserirOrdenado(vetor, &tamanho, val);
                printf("Valor inserido com sucesso.\n");
                break;
            }
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}