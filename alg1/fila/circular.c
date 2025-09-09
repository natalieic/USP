#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct fila_{
    ITEM* array[TAM_MAX];
    int inicio, fim, tamanho;
};

FILA* fila_criar(void){
    FILA* fila=malloc(sizeof(FILA));
    if(fila!=NULL){
        fila->inicio=0;
        fila->fim=0;
        fila->tamanho=0;
    }

    return fila;
}

bool fila_inserir(FILA* fila, ITEM* item){
    if(fila==NULL||fila->tamanho==TAM_MAX)
        return false;
    fila->array[fila->fim]=item;
    fila->fim=(fila->fim+1)%TAM_MAX;
    fila->tamanho++;

    return true;
}

ITEM* fila_remover(FILA* fila){
    if(fila==NULL||fila->tamanho==0)
        return NULL;
    ITEM* item=fila->array[fila->inicio];
    fila->array[fila->inicio]=NULL;
    fila->inicio=(fila->inicio+1)%TAM_MAX;
    fila->tamanho--;

    return item;
}

void fila_apagar(FILA** fila){
    if(*fila!=NULL){
        int i=(*fila)->inicio;
        while((*fila)->array[i]!=(*fila)->array[(*fila)->fim]){
            item_apagar((*fila)->array+i);
            i=(i+1)%TAM_MAX;
        }
        free(*fila);
        *fila=NULL;
    }
}

bool fila_inverter(FILA* fila){
    if(fila==NULL)
        return false;
    int i=fila->inicio, j=(fila->fim+TAM_MAX-1)%TAM_MAX;
    ITEM* aux;
    for(int k=0; k<fila->tamanho/2; k++){
        aux=fila->array[i];
        fila->array[i]=fila->array[j];
        fila->array[j]=aux;

        i=(i+1)%TAM_MAX;
        j=(j+TAM_MAX-1)%TAM_MAX;
    }

    return true;
}