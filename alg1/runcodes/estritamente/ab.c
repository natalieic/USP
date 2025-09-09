#include "ab.h"
#include "item.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ NO;
struct no_{
    ITEM* item;
    NO *esq, *dir;
};

struct arv_bin{
    NO* raiz;
    int profundidade;
};

AB* ab_criar(void){
    AB* T=(AB*)malloc(sizeof(AB));
    if(T!=NULL){
        T->raiz=NULL;
        T->profundidade=-1;
    }

    return T;
}

NO* dfs(NO* raiz, int chave){
    if(raiz!=NULL){
        if(chave!=item_get_chave(raiz->item)){
            NO* pai=dfs(raiz->esq, chave);
            if(pai!=NULL)
                return pai;
            return dfs(raiz->dir, chave);
        }
    }

    return raiz;
}

// item a ser inserido, chave do pai
bool ab_inserir(AB *T, ITEM *item, int lado, int chave){
    if(T==NULL)
        return false;
    
    NO* novo=(NO*)malloc(sizeof(NO));
    novo->item=item;
    novo->esq=NULL;
    novo->dir=NULL;

    if(T->profundidade==-1){
        T->raiz=novo;
        T->profundidade=0;
    }else{
        NO* pai=dfs(T->raiz, chave);
        if(pai==NULL){
            free(novo);
            return false;
        }

        if(lado)
            pai->dir=novo;
        else
            pai->esq=novo;
    }

    return true;
}

void preordem(NO* raiz){
    if(raiz!=NULL){
        printf("%d ", item_get_chave(raiz->item));
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
}

void ab_imprimir(AB* T){
    if(T!=NULL && T->raiz!=NULL)
        preordem(T->raiz);
    printf("\n");
}

void apagar_no(NO* raiz){
    if(raiz==NULL)
        return;
    apagar_no(raiz->esq);
    apagar_no(raiz->dir);
    item_apagar(&raiz->item);
    free(raiz); 
}

void ab_apagar_arvore(AB **T){
    if(*T!=NULL){
        apagar_no((*T)->raiz);
        free(*T);
        *T=NULL;
    }
}

int aux_estritamente(NO* raiz){
    if(raiz==NULL)
        return 0;
    bool tem_esq=(raiz->esq!=NULL);
    bool tem_dir=(raiz->dir!=NULL);
    if(tem_esq^tem_dir)
        return 1;
    if(tem_esq&tem_dir)
        return (aux_estritamente(raiz->esq)||aux_estritamente(raiz->dir)) ? 1 : 0;
    else
        return 0;
}


/* 0 se é eb e 1 se não é eb */
int ab_estritamente_binaria(AB* T){
    int eb=0;
    if(T!=NULL && T->raiz!=NULL)
        eb=aux_estritamente(T->raiz);

    return eb;
}