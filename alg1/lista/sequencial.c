#include "lista.h"
#include <stdlib.h>
#define TAM_MAX 500000

struct lista_{
    ITEM* array[TAM_MAX];
    int fim;
    bool ordenada;
};

int busca_binaria(LISTA* lista, int chave, int inicio, int fim){
    if(inicio==fim)
        return inicio;
    int meio=(inicio+fim)/2;
    if(chave>item_get_chave(lista->array[meio]))
        return busca_binaria(lista, chave, meio+1, lista->fim);
    else
        busca_binaria(lista, chave, 0, meio-1);
}

ITEM* lista_remover(LISTA* lista, int chave){
    if(lista==NULL)
        return NULL;
    if(lista->ordenada){
        busca_binaria(lista, chave, 0, lista->fim);
    }
}