#include <stdlib.h>
#include <stdio.h>
#include "../item/item.h"
#include "ab.h"

typedef struct No NO;

struct No{
    ITEM* item;
    NO *esq, *dir;
};

struct arv_bin{
    NO* raiz;
    int profundidade;
};

AB* ab_criar(void){
    AB *r=(AB*)malloc(sizeof(AB));
    if(r!=NULL){
        r->raiz=NULL;
        r->profundidade=-1;
    }

    return r;
}

NO* busca_preordem(NO* raiz, int chave){
    if(raiz!=NULL){
        if(item_get_chave(raiz->item) != chave){
            NO* no = busca_preordem(raiz->esq, chave);
            if(no == NULL)
                no = busca_preordem(raiz->dir, chave);
            return no;
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
        NO* pai=busca_preordem(T->raiz, chave);
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

void ab_preordem(NO* raiz){
    if(raiz!=NULL){
        printf("%d ", item_get_chave(raiz->item));
        ab_preordem(raiz->esq);
        ab_preordem(raiz->dir);
    }
}

void ab_emordem(NO* raiz){
    if(raiz!=NULL){
        ab_emordem(raiz->esq);
        printf("%d ", item_get_chave(raiz->item));
        ab_emordem(raiz->dir);
    }
}

void ab_posordem(NO* raiz){
    if(raiz!=NULL){
        ab_posordem(raiz->esq);
        ab_posordem(raiz->dir);
        printf("%d ", item_get_chave(raiz->item));
    }
}

void ab_imprimir(AB* T){
    if(T!=NULL && T->raiz!=NULL)
        ab_preordem(T->raiz);
    printf("\n");
}

// NO* busca_preordem(NO* raiz, int chave){
//     if(raiz!=NULL){
//         if(item_get_chave(raiz->item)!=chave){
//             busca_preordem(raiz->esq, chave);
//             busca_preordem(raiz->dir, chave);
//         }
//     }

//     return raiz;
// }

// int aux_profundidade(NO* raiz){
//     if(raiz==NULL)
//         return -1;
//     int e=aux_profundidade(raiz->esq);
//     int d=aux_profundidade(raiz->dir);

//     return ((e > d) ? e : d) + 1;
// }

// int numero_de_nos(AB* T){
//     int n = 0;
//     if(T != NULL && T->raiz != NULL){
//         NO* pai = T->raiz;
//         do{
//             bool esq = p->esq;
//             bool dir = p->dir;
//             if(esq^dir)
//                 n++;
//             else if(esq & dir)
//                 n += 2;
//         } while(p != NULL)
//     }

//     return n;
// }

int aux_profundidade(NO* raiz){
    if(raiz == NULL)
        return -1;
    int d = aux_profundidade(raiz->dir);
    int e = aux_profundidade(raiz->esq);

    return (d > e ? d : e) + 1;
}

int ab_profundidade(AB* T){
    int d = -1;
    if(T != NULL && T ->raiz != NULL){
        d = aux_profundidade(T->raiz);
    }

    return d;
}

void apagar_no(NO** raiz){
    if(*raiz == NULL)
        return;
    apagar_no(&(*raiz)->esq);
    apagar_no(&(*raiz)->dir);
    item_apagar(&(*raiz)->item);
    free(*raiz);
    *raiz = NULL;
}

void ab_apagar_arvore(AB** T){
    if(T != NULL){
        apagar_no(&(*T)->raiz);
        free(*T);
        *T = NULL;
    }
}

int aux_qtd(NO* raiz){
    if(raiz == NULL)
        return 0;
    return aux_qtd(raiz->esq) + aux_qtd(raiz->dir) + 1;
}

int ab_qtd_elementos(AB* T){
    int qtd = -1;
    if(T != NULL && T->raiz != NULL){
        qtd = aux_qtd(T->raiz);
    }
    return qtd;
}

int aux_maior(NO* raiz, int* max){
    if(raiz != NULL && raiz->item != NULL){
        int chave = item_get_chave(raiz->item);
        if(chave > *max){
            *max = chave;
        }
        aux_maior(raiz->esq, max);
        aux_maior(raiz->dir, max);
    }

    return *max;
}

int ab_maior(AB* T){
    int maior = -ERRO;
    if(T != NULL && T->raiz != NULL){
        maior = aux_maior(T->raiz, &maior);
    }

    return maior;
}

int aux_soma(NO* raiz){
    if(raiz == NULL)
        return 0;
    return aux_soma(raiz->esq) + aux_soma(raiz->dir) + item_get_chave(raiz->item);
}

int ab_soma(AB* T){
    int soma = ERRO;
    if(T != NULL && T->raiz != NULL){
        soma = aux_soma(T->raiz);
    }

    return soma;
}

bool aux_completa_cheia(NO* n){
    if(n && !(n->esq ^ n->dir))
        return !(aux_completa_cheia(n->esq) ^ aux_completa_cheia(n->dir));
    return false;
}

bool ab_completa_cheia(AB* T){
    if(T){
        return aux_completa_cheia(T->raiz);
    }
    return false;
}