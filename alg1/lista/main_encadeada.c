#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main(void){
    
    LISTA *lista;
    ITEM *item;
    
    lista = lista_criar(true);
        
    lista_inserir (lista, item_criar(12, NULL));
    lista_inserir (lista, item_criar(1, NULL));    
    lista_inserir (lista, item_criar(8, NULL));
    lista_inserir (lista, item_criar(18, NULL));
    lista_inserir (lista, item_criar(2, NULL));

    lista_imprimir(lista);

    item = lista_remover(lista, 12); // remove no do meio da lista
    item_apagar(&item); //apaga o item retornado. responsabilidade do chamado em vez de ser ser lista_remover(); decisão de projeto
    lista_imprimir(lista);
    
    item = lista_remover(lista, 1); //remove 1o item da lista
    item_apagar(&item);
    lista_imprimir(lista);

        
    lista_apagar(&lista);
    lista_imprimir(lista);
   	
    return (0);
}


