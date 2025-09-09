#include "ab.h"
#include <stdlib.h>
typedef AB ABB;

bool abb_inserir(ABB* T, ITEM* item){
    if(T!=NULL){
        chave=item_get_chave(item);
        NO* pai=acha_pai(T->raiz, chave);
        if(pai!=NULL){
            NO* novo=(NO*)malloc(sizeof(NO));
            novo->item=item;
            novo->esq=NULL;
            novo->dir=NULL;

            if(chave<item_get_chave(pai))
                pai->esq=novo;
            else
                pai->dir=novo;

            return true;
        }
    }

    return false;
}

NO* acha_pai(NO* raiz, int chave){
    NO* pai;
    if(raiz==NULL||chave==item_get_chave(raiz->item))
        pai=NULL;
    else if(chave>item_get_chave(raiz->item)){
        if(raiz->dir==NULL)
            pai=raiz;
        else
            pai=acha_pai(raiz->dir, chave);
    } else if(raiz->esq==NULL)
        pai=raiz;
    else
        pai=acha_pai(raiz->esq, chave);

    return pai;
}

bool abb_inserir(ABB* T, ITEM* item){
    if(T!=NULL){
        NO* novo=cria_no(item);
        if(novo!=NULL){
            novo=inserir_no(T->raiz, novo);
            //inserir_no(&T->raiz, novo);

            return true;
        }
    }

    return false;
}

NO* inserir_no(NO* raiz, NO* no){
    if(raiz==NULL)
        raiz=no;
    else if(item_get_chave(no->item)<item_get_chave(raiz->item))
        raiz->esq=abb_inserir_no(raiz->esq, no);
    else if(item_get_chave(no->item)>item_get_chave(raiz->item))
        raiz->dir=abb_inserir_no(raiz->dir, no);
    
    return raiz;
}

void inserir_no(NO** raiz, NO* no){
    if(*raiz==NULL)
        *raiz=no;
    else if(item_get_chave(no->item)<item_get_chave((*raiz)->item))
        inserir_no(())
}

abb_inserir_iterativo(){}

ITEM* abb_busca(ABB* T, int chave){
    if(T!=NULL){
    NO* no=busca_no(T->raiz, int chave);
    if(no!=NULL)
        return no->item;
    }

    return NULL;
}

NO* busca_no(NO* raiz, int chave){
    if(raiz==NULL||chave==item_get_chave(raiz->item))
        return raiz;
    if(chave<item_get_chave(raiz->item))
        return busca_no(raiz->esq, chave);
    else
        return busca_no(raiz->dir, chave);
}

busca_no_iterativo(){}

void troca_max_esq(NO* troca, NO* raiz, NO* ant){
    if(troca->esq!=NULL){ // Não é o maior da sub-árvore
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }
    if(raiz==ant) // Primeira chamada da recursão, não entrou na sub-árvore direita
        ant->esq=troca->esq;
    else
        ant->dir = troca->esq;

    raiz->item = troca->item;
    free(troca);
    troca = NULL;
}

bool abb_remover_aux(NO** raiz, int chave){
    if(*raiz==NULL)
        return false;
    if(chave==item_get_chave((*raiz)->item)){
        if((*raiz)->esq==NULL||(*raiz)->dir==NULL){ // Um ou nenhum filho
            NO* p=*raiz;
            if((*raiz)->esq==NULL)
                *raiz=(*raiz)->dir;
            else
                *raiz=(*raiz)->esq;
            free(p);
            p=NULL;
        }else // Dois filhos
            troca_max_esq((*raiz)->esq, *raiz, *raiz);
        return true;
    }
    if(chave<item_get_chave((*raiz)->item))
        return abb_remover_aux(&(*raiz)->esq, chave);
    return abb_remover_aux(&(*raiz)->dir, chave);
}

bool abb_remover(ABB* T, int chave){
    if(T!=NULL)
        return abb_remover_aux(&T->raiz, chave);
    return false;
}