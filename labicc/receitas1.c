#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECEITAS 100

typedef struct {
    char nome[21];
    int ingredientes[5];
} Receita;

Receita *receitas[MAX_RECEITAS];
int qtdReceitas = 0;
int estoque[5] = {0};

void liberarMemoria() {
    for (int i = 0; i < qtdReceitas; i++) {
        free(receitas[i]);
    }
}

void registrarReceita(char *nome, int *ingredientes) {
    if (qtdReceitas >= MAX_RECEITAS) {
        return;
    }
    Receita *novaReceita = (Receita *)malloc(sizeof(Receita));
    if (novaReceita == NULL) {
        return;
    }
    strcpy(novaReceita->nome, nome);
    memcpy(novaReceita->ingredientes, ingredientes, sizeof(int) * 5);
    receitas[qtdReceitas++] = novaReceita;
}

void cadastrarCompra(int *quantidades) {
    for (int i = 0; i < 5; i++) {
        estoque[i] += quantidades[i];
    }
}

void fazerReceita(int numeroReceita) {
    if (numeroReceita < 0 || numeroReceita >= qtdReceitas) {
        printf("Receita nao encontrada!\n");
        return;
    }
    Receita *receita = receitas[numeroReceita];
    for (int i = 0; i < 5; i++) {
        if (estoque[i] < receita->ingredientes[i]) {
            printf("%s insuficiente\n", i == 0 ? "Farinha" : 
                                     i == 1 ? "Ovos" : 
                                     i == 2 ? "Oleo" : 
                                     i == 3 ? "Acucar" : "Chocolate");
            return;
        }
    }
    for (int i = 0; i < 5; i++) {
        estoque[i] -= receita->ingredientes[i];
    }
    printf("%s feita com sucesso!\n", receita->nome);
}

int main() {
    char comando;
    char nome[21];
    int parametros[6];
    int numReceita;

    while (1) {
        scanf(" %c", &comando);
        switch (comando) {
            case 'R':
                scanf(" %20s %d %d %d %d %d", nome, &parametros[0], &parametros[1], &parametros[2], &parametros[3], &parametros[4]);
                registrarReceita(nome, parametros);
                break;
            case 'C':
                scanf("%d %d %d %d %d", &parametros[0], &parametros[1], &parametros[2], &parametros[3], &parametros[4]);
                cadastrarCompra(parametros);
                break;
            case 'F':
                scanf("%d", &numReceita);
                fazerReceita(numReceita);
                break;
            case 'S':
                printf("Quantidade no estoque:\n");
                printf("Acucar: %d\n", estoque[3]);
                printf("Chocolate: %d\n", estoque[4]);
                printf("Farinha: %d\n", estoque[0]);
                printf("Oleo: %d\n", estoque[2]);
                printf("Ovos: %d\n", estoque[1]);
                printf("Receitas cadastradas: %d\n", qtdReceitas);
                liberarMemoria();
                return 0;
            default:
                printf("Codigo invalido\n");
                break;
        }
    }

    return 0;
}
