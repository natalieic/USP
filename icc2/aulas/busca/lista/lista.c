#include "lista.h"

typedef struct no_ NO;
struct no_{
    int chave;
    void* dado;
    NO* proximo;
};
struct lista_{
    NO* inicio, *fim;
    int tamanho;
};

NO* criar_no(int C, void* D){
    NO* novo=(NO*)malloc(sizeof(NO));
    if(novo!=NULL){
        novo->chave=C;
        novo->dado=D;
        novo->proximo=NULL;
    }

    return novo;
}