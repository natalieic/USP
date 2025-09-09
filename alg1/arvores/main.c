#include "ab.h"
#include "../item/item.h"
#include "stdio.h"

int main(void){
    AB* arvore = ab_criar();
    ab_inserir(arvore, item_criar(1, &arvore), 0, 0);
    ab_inserir(arvore, item_criar(2, &arvore), 0, 1);
    ab_inserir(arvore, item_criar(3, &arvore), 1, 1);
    ab_inserir(arvore, item_criar(4, &arvore), 0, 2);
    ab_inserir(arvore, item_criar(5, &arvore), 1, 2);

    ab_imprimir(arvore);

    printf("soma: %d\n", ab_soma(arvore));
    ab_apagar_arvore(&arvore);

}