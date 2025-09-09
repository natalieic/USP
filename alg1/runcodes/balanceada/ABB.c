#include "ABB.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ NO;
struct no_{
    ITEM* item;
    NO *esq, *dir;
};
struct abb{
    NO* raiz;
};

ABB* abb_criar(void){
    ABB* T = (ABB*) malloc(sizeof(ABB));
    if(T != NULL){
        T->raiz = NULL;
    }

    return T;
}

NO* inserir_no(NO** raiz, NO* no){
    if(*raiz == NULL)
        *raiz = no;
    else if(item_get_chave(no->item) < item_get_chave((*raiz)->item))
        (*raiz)->esq = inserir_no(&(*raiz)->esq, no);
    else if(item_get_chave(no->item) > item_get_chave((*raiz)->item))
        (*raiz)->dir = inserir_no(&(*raiz)->dir, no);
    
    return *raiz;
}

bool abb_inserir(ABB* T, ITEM* item){
    if(T != NULL){
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->esq = NULL; novo->dir = NULL; novo->item = item;
        if(novo != NULL){
            novo = inserir_no(&T->raiz, novo);

            return true;
        }
    }

    return false;
}

// NO* acha_pai(NO* raiz, int chave){
//     NO* pai;
//     if(raiz==NULL||chave==item_get_chave(raiz->item))
//         pai=NULL;
//     else if(chave>item_get_chave(raiz->item)){
//         if(raiz->dir==NULL)
//             pai=raiz;
//         else
//             pai=acha_pai(raiz->dir, chave);
//     } else if(raiz->esq==NULL)
//         pai=raiz;
//     else
//         pai=acha_pai(raiz->esq, chave);

//     return pai;
// }

// bool abb_inserir(ABB* T, ITEM* item){
//     if(T!=NULL){
//         int chave=item_get_chave(item);
//         NO* pai=acha_pai(T->raiz, chave);
//         if(pai!=NULL){
//             NO* novo=(NO*)malloc(sizeof(NO));
//             novo->item=item;
//             novo->esq=NULL;
//             novo->dir=NULL;

//             if(chave<item_get_chave(pai->item))
//                 pai->esq=novo;
//             else
//                 pai->dir=novo;

//             return true;
//         }
//     }

//     return false;
// }

void ab_emordem(NO* raiz){
    if(raiz != NULL){
        ab_emordem(raiz->esq);
        printf("%d ", item_get_chave(raiz->item));
        ab_emordem(raiz->dir);
    }
}

void abb_imprimir(ABB *T){
    if(T != NULL)
        ab_emordem(T->raiz);
}

void apagar_no(NO** no){
    if(*no != NULL){
        apagar_no(&(*no)->esq);
        apagar_no(&(*no)->dir);
        free(*no);
        *no = NULL;
    }
}

void abb_apagar(ABB **T){
    if(*T != NULL){
        apagar_no(&(*T)->raiz);
        free(*T);
        *T = NULL;
    }
}

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

NO* busca_no(NO* raiz, int chave){
    if(raiz==NULL||chave==item_get_chave(raiz->item))
        return raiz;
    if(chave<item_get_chave(raiz->item))
        return busca_no(raiz->esq, chave);
    else
        return busca_no(raiz->dir, chave);
}

ITEM* abb_busca(ABB* T, int chave){
    if(T!=NULL){
    NO* no=busca_no(T->raiz, chave);
    if(no!=NULL)
        return no->item;
    }

    return NULL;
}

bool abb_vazia(ABB* T){
    bool vazia = true;
    if(T != NULL && T->raiz != NULL)
        vazia = false;
    return vazia;
}

int qtd_nos(NO* raiz){
    if(raiz != NULL){
        return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
    }
    return 0;
}

// o número de nós de suas sub-árvores esquerda e direita difere em, no máximo, 1
bool abb_perfeitamente_balanceada(ABB *T){
    bool pb = true;
    if(T != NULL && T->raiz != NULL){
        int esq = qtd_nos(T->raiz->esq);
        int dir = qtd_nos(T->raiz->dir);

        if(abs(esq-dir) > 1){
            pb = false;
        }
    }

    return pb;
}