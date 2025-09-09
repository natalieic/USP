#include "fila.h"
#include <stdlib.h>

typedef struct no_{
    ITEM* item;
    struct no_ *proximo;
}NO;

struct fila_{
    NO *inicio, *fim;
    int tamanho;
};

FILA* fila_criar(void){
    FILA* fila=malloc(sizeof(FILA));
    if(fila!=NULL){
        fila->inicio=NULL;
        fila->fim=NULL;
        fila->tamanho=0;
    }

    return fila;
}

bool fila_inserir(FILA* fila, ITEM* item){
    if(fila_cheia(fila))
        return false;
    NO* no=malloc(sizeof(NO));
    no->item=item;
    no->proximo=NULL;
    if(fila->tamanho==0)
        fila->inicio=no;
    else
        fila->fim->proximo=no;
    fila->fim=no;
    fila->tamanho++;

    return true;
}

ITEM* fila_remover(FILA* fila){
    if(fila==NULL||fila->tamanho==0)
        return NULL;
    ITEM* item=fila->inicio->item;
    NO* p=fila->inicio;
    fila->inicio=fila->inicio->proximo;
    free(p); p=NULL;
    fila->tamanho--;
    if(fila->tamanho==0)
        fila->fim=NULL;

    return item;
}

ITEM* fila_frente(FILA* fila){
    if(fila==NULL||fila->inicio==NULL)
        return NULL;

        return fila->inicio->item;
}

bool fila_cheia(FILA* fila){
    NO* no=malloc(sizeof(NO));
    if(no==NULL)
        return true;
    free(no);
    return false;
}

void fila_apagar(FILA** fila){
    if(*fila!=NULL){
        if((*fila)->tamanho==0){
            free(*fila);
            *fila=NULL;
            return;
        }
        ITEM* item=fila_remover(*fila);
        item_apagar(&item);
        fila_apagar(fila);
    }
}

bool fila_inverter(FILA* fila){
    if(fila==NULL)
        return false;
    if(fila->tamanho!=0){
        ITEM* item=fila_remover(fila);
        fila_inverter(fila);
        fila_inserir(fila, item);
    }
    return true;
}

/*void apagar_no(NO** no){
    if((*no)->proximo!=NULL)
        apagar_no(&((*no)->proximo));

    item_apagar(&((*no)->item));
    free(*no);
    *no=NULL;
}

void fila_apagar(FILA** fila){
    if(*fila==NULL)
        return;
    if((*fila)->inicio!=NULL)
        apagar_no(&(*fila)->inicio);
    (*fila)->fim=NULL;
    free(*fila);
    *fila=NULL;
}*/