#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char cpf[12];
    int idade;
    float saldo;
    float credito;
} Cliente;

void remover_espacos(char *str) {
    char *i = str, *j = str;
    while(*j != 0) {
        *i = *j++;
        if(*i != ' ') {
            i++;
        }
    }
    *i = 0;
}

int main() {
    int n;
    scanf("%d\n", &n);

    Cliente *clientes = (Cliente *)malloc(n * sizeof(Cliente));
    char linha[100];

    for (int i = 0; i < n; i++) {
        fgets(linha, sizeof(linha), stdin);

        char *token = strtok(linha, ",");
        
        clientes[i].nome = (char *)malloc((strlen(token) + 1) * sizeof(char));
        strcpy(clientes[i].nome, token);
        remover_espacos(clientes[i].nome);

        token = strtok(NULL, ",");
        remover_espacos(token);
        strcpy(clientes[i].cpf, token);

        token = strtok(NULL, ",");
        clientes[i].idade = atoi(token);

        token = strtok(NULL, ",");
        clientes[i].saldo = atof(token);

        token = strtok(NULL, ",");
        clientes[i].credito = atof(token);
    }

    for (int i = 0; i < n; i++) {
        printf("Dados da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("Credito: %.2f\n\n", clientes[i].credito);
    }

    int encontrou_endividados = 0;
    printf("Pessoas endividadas:\n");
    for (int i = 0; i < n; i++) {
        if (clientes[i].credito > clientes[i].saldo) {
            printf("Nome: %s\n", clientes[i].nome);
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Divida: %.2f\n", clientes[i].credito - clientes[i].saldo);
            encontrou_endividados = 1;
            if(i<n-1)
                printf("\n");
        }
    }
    if (!encontrou_endividados) {
        printf("Nenhuma pessoa endividada encontrada.\n");
    }

    for (int i = 0; i < n; i++) {
        free(clientes[i].nome);
    }
    free(clientes);

    return 0;
}