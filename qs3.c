#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

// ======= STRUCT DO CADASTRO =======
typedef struct {
    int numero;
    char nome[50];
    char cpf[20];
    char telefone[20];
    float saldo;
} Conta;


// =================================================
// (a) FUNÇÃO DE BUSCA
// Retornos:
// -1 → cadastro vazio
// -2 → conta não encontrada
// >=0 → posição encontrada
// =================================================
int buscarConta(Conta cadastro[], int qtd, int numeroBusca) {

    if (qtd == 0)
        return -1; // cadastro vazio

    for (int i = 0; i < qtd; i++) {
        if (cadastro[i].numero == numeroBusca)
            return i; // achou
    }

    return -2; // não achou
}


// =================================================
// (b) PROCEDIMENTO PARA CADASTRAR CONTA
// =================================================
void cadastrarConta(Conta cadastro[], int *qtd, int numeroNovo) {

    // primeiro verificar se já existe
    int pos = buscarConta(cadastro, *qtd, numeroNovo);

    if (pos >= 0) {
        printf("\nERRO: Já existe uma conta com esse numero.\n");
        return;
    }

    if (*qtd >= MAX_CONTAS) {
        printf("\nERRO: Limite de contas atingido.\n");
        return;
    }

    // Prosseguir com cadastro
    cadastro[*qtd].numero = numeroNovo;

    printf("Nome do titular: ");
    fflush(stdin);
    fgets(cadastro[*qtd].nome, 50, stdin);
    cadastro[*qtd].nome[strcspn(cadastro[*qtd].nome, "\n")] = '\0';

    printf("CPF: ");
    fflush(stdin);
    fgets(cadastro[*qtd].cpf, 20, stdin);
    cadastro[*qtd].cpf[strcspn(cadastro[*qtd].cpf, "\n")] = '\0';

    printf("Telefone: ");
    fflush(stdin);
    fgets(cadastro[*qtd].telefone, 20, stdin);
    cadastro[*qtd].telefone[strcspn(cadastro[*qtd].telefone, "\n")] = '\0';

    printf("Saldo inicial: R$ ");
    scanf("%f", &cadastro[*qtd].saldo);

    (*qtd)++;

    printf("\nConta cadastrada com sucesso!\n");
}


// =================================================
// (c) CONSULTAR SALDO
// =================================================
void consultarSaldo(Conta cadastro[], int qtd, int numero) {
    int pos = buscarConta(cadastro, qtd, numero);

    if (pos == -1 || pos == -2) {
        printf("\nConta NAO cadastrada.\n");
        return;
    }

    printf("\nSaldo da conta %d: R$ %.2f\n", numero, cadastro[pos].saldo);
}


// =================================================
// (d) DEPOSITAR
// =================================================
void depositar(Conta cadastro[], int qtd, int numero) {
    int pos = buscarConta(cadastro, qtd, numero);

    if (pos == -1 || pos == -2) {
        printf("\nConta NAO cadastrada.\n");
        return;
    }

    float valor;
    printf("Valor do deposito: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("\nValor invalido.\n");
        return;
    }

    cadastro[pos].saldo += valor;

    printf("\nDeposito realizado. Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
}


// =================================================
// (e) SACAR
// =================================================
void sacar(Conta cadastro[], int qtd, int numero) {
    int pos = buscarConta(cadastro, qtd, numero);

    if (pos == -1 || pos == -2) {
        printf("\nConta NAO cadastrada.\n");
        return;
    }

    float valor;
    printf("Valor do saque: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("\nValor invalido.\n");
        return;
    }

    if (valor > cadastro[pos].saldo) {
        printf("\nSaldo insuficiente!\n");
        return;
    }

    cadastro[pos].saldo -= valor;

    printf("\nSaque realizado. Novo saldo: R$ %.2f\n", cadastro[pos].saldo);
}


// =================================================
// (f) LISTAR TODAS AS CONTAS
// =================================================
void listarContas(Conta cadastro[], int qtd) {

    if (qtd == 0) {
        printf("\nNenhuma conta cadastrada.\n");
        return;
    }

    printf("\n=== LISTA DE CONTAS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("Conta: %d | Titular: %s | Telefone: %s\n",
               cadastro[i].numero,
               cadastro[i].nome,
               cadastro[i].telefone);
    }
}


// =================================================
// PROGRAMA PRINCIPAL
// =================================================
int main() {

    Conta corrente[MAX_CONTAS], poupanca[MAX_CONTAS];
    int qtdCorr = 0, qtdPoup = 0;

    int opcao, tipo, numero;

    do {
        printf("\n\n===== BANCO DINHEIRO CERTO =====\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Listar contas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("\nTipo de conta:\n1 - Corrente\n2 - Poupanca\nEscolha: ");
        scanf("%d", &tipo);

        Conta *cadastro;
        int *qtd;

        if (tipo == 1) {
            cadastro = corrente;
            qtd = &qtdCorr;
        } else {
            cadastro = poupanca;
            qtd = &qtdPoup;
        }

        switch (opcao) {

            case 1:
                printf("\nNumero da nova conta: ");
                scanf("%d", &numero);
                cadastrarConta(cadastro, qtd, numero);
                break;

            case 2:
                printf("\nNumero da conta: ");
                scanf("%d", &numero);
                consultarSaldo(cadastro, *qtd, numero);
                break;

            case 3:
                printf("\nNumero da conta: ");
                scanf("%d", &numero);
                depositar(cadastro, *qtd, numero);
                break;

            case 4:
                printf("\nNumero da conta: ");
                scanf("%d", &numero);
                sacar(cadastro, *qtd, numero);
                break;

            case 5:
                listarContas(cadastro, *qtd);
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
