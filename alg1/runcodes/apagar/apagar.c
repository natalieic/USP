#include "fila.h"
#include <stdlib.h>

#ifndef _STRUCTS_
    #define _STRUCTS_

    typedef struct no_ {
        ITEM* item;
        struct no_* proximo;
    }noObj;
    typedef noObj NO;

    typedef struct fila_ {
        NO* inicio;
        NO* fim;
        int tamanho;
    }filaObj;
    typedef filaObj FILA;
#endif

void apagar_no(NO** no){
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
}