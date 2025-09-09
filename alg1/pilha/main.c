#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(void){
    char str[100];

    fgets(str, sizeof(str), STDIN);

    pilha_empilhar(p, item_criar(6, malloc(1)));
    pilha_empilhar(p, item_criar(5, malloc(1)));
    pilha_empilhar(p, item_criar(4, malloc(1)));
    pilha_empilhar(p, item_criar(3, malloc(1)));
    pilha_empilhar(p, item_criar(2, malloc(1)));
    pilha_empilhar(p, item_criar(1, malloc(1)));

    pilha_desempilhar(p);
    pilha_desempilhar(p);
    pilha_desempilhar(p);
    pilha_desempilhar(p);
    pilha_desempilhar(p);

    pilha_print(p);

    pilha_inverter(p);

    pilha_print(p);

    return 0;
}