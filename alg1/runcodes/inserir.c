#include "lista.h"

#ifndef STRUCTS_

#define STRUCTS_

struct lista_{ 
    ITEM *lista[TAM_MAX];
    int inicio, fim, tamanho;
};
#endif

int lista_busca(LISTA* lista, int chave, int min, int max){
    if(chave>item_get_chave(lista->lista[max]))
            return max+1;
    if(min==max)
        return min;
    int meio=(min+max)/2;
    if(chave>item_get_chave(lista->lista[meio]))
        return lista_busca(lista, chave, meio+1, max);
    else
        return lista_busca(lista, chave, min, meio);
}

bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista==NULL||lista_cheia(lista))
        return false;
    int pos=lista_busca(lista, item_get_chave(item), lista->inicio, lista->fim-1);

    for(int i=lista->fim; i>pos; i--)
        lista->lista[i]=lista->lista[i-1];

    lista->lista[pos]=item;
    lista->fim++;
    lista->tamanho++;

    return true;
}