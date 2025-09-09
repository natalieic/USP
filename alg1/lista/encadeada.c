#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ NO;
struct no_{
    ITEM* item;
    NO* proximo;
};

struct lista_{
    NO *inicio, *fim;
    int tamanho;
    bool ordenada;
};

LISTA* lista_criar(bool ordenada){
    LISTA* lista=malloc(sizeof(LISTA));
    if(lista!=NULL){
        lista->inicio=NULL;
        lista->fim=NULL;
        lista->tamanho=0;
        lista->ordenada=ordenada;
    }

    return lista;
}

bool inserir_fim(LISTA* lista, NO* no){
    lista->fim->proximo=no;
    no->proximo=NULL;
    lista->fim=no;
    lista->tamanho++;
    return true;
}

bool inserir_ordenada(LISTA* lista, NO* no){
    int chave=item_get_chave(no->item);

    if(chave<item_get_chave(lista->inicio->item)){
        no->proximo=lista->inicio;
        lista->inicio=no;
        lista->tamanho++;
    }
    else if(chave>=item_get_chave(lista->fim->item))
        inserir_fim(lista, no);
    else{
        NO* aux=lista->inicio;
        while(aux->proximo!=NULL && item_get_chave(aux->proximo->item)<=chave)
            aux=aux->proximo;
        
        no->proximo=aux->proximo;
        aux->proximo=no;
        lista->tamanho++;
    }
    
    return true;
}

bool lista_inserir(LISTA* lista, ITEM* item){
    NO* no=malloc(sizeof(NO));
    if(lista==NULL || no==NULL)
        return false;
    no->item=item;
    if(lista->tamanho==0){
        lista->inicio=no;
        lista->fim=no;
        no->proximo=NULL;
        lista->tamanho++;
        return true;
    }
    if(lista->ordenada)
        return inserir_ordenada(lista, no);
    return inserir_fim(lista, no);
}

bool lista_apagar(LISTA** lista){
    if(*lista==NULL)
        return false;
    NO *ptr1, *ptr2;
    ptr1=(*lista)->inicio;
    while(ptr1!=NULL){
        item_apagar(&(ptr1->item));
        ptr2=ptr1->proximo;
        free(ptr1);
        ptr1=ptr2;
    }
    
    free(*lista);
    *lista=NULL;

    return true;
}

/* otimizar para a remoção ordenada */
ITEM* lista_remover(LISTA* lista, int chave){
    if(lista==NULL || lista->tamanho==0)
        return NULL;
    NO* aux=lista->inicio, *p=lista->inicio;
    while(aux!=NULL && item_get_chave(aux->item)!=chave){
        p=aux;
        aux=aux->proximo;
    }

    ITEM* item;
    if(aux==NULL)
        item=NULL;
    else{
        item=aux->item;
        if(aux==lista->inicio)
            lista->inicio=aux->proximo;
        if(aux==lista->fim)
            lista->fim=p;
        p->proximo=aux->proximo;
        free(aux);
        lista->tamanho--;
    }

    return item;
}

/* otimizar a busca ordenada */
ITEM* lista_busca(LISTA* lista, int chave){
    if(lista==NULL || lista->tamanho==0)
        return NULL;
    NO* aux=lista->inicio;
    while(aux!=NULL && item_get_chave(aux->item)!=chave)
        aux=aux->proximo;

    if(aux==NULL)
        return NULL;
    return aux->item;
}

/* testar lista busca recursiva da prova */

int lista_tamanho(LISTA* lista){
    if(lista==NULL)
        return ERRO;
    return lista->tamanho;
}

bool lista_vazia(LISTA* lista){
    if(lista==NULL||lista->tamanho==0)
        return true;
    return false;
}

bool lista_cheia(LISTA* lista){
    if(lista==NULL || malloc(sizeof(NO))==NULL)
        return true;
    return false;
}

void lista_imprimir(LISTA* lista){
    if(lista==NULL)
        return;
    NO* p=lista->inicio;
    while(p!=NULL){
        printf("[%d] ", item_get_chave(p->item));
        p=p->proximo;
    }
    printf("\n");
}