#include "avl.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
typedef struct no_ NO;

struct avl_{
    NO* raiz;
};

struct no_{
    int dado, altura;
    NO *esq, *dir;
};

AVL* avl_criar(void){
    AVL* A = (AVL*) malloc(sizeof(AVL));
    if(A){
        A->raiz = NULL;
    }
    return A;
}

NO* criar_no(int dado){
    NO* novo = (NO*) malloc(sizeof(NO));
    if(novo){
        novo->dado = dado;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
    }
}

int altura_no(NO* p){
    return (p ? p->altura : -1);
}

NO* rotacao_esq(NO* p){
        NO* q = p->dir;
        p->dir = q->esq;
        q->esq = p;

        p->altura = max(altura_no(p-> esq), altura_no(p->dir)) + 1;
        q->altura = max(altura_no(q-> esq), altura_no(q->dir)) + 1;

        return q;
}

NO* rotacao_dir(NO* p){
        NO* q = p->esq;
        p->esq = q->dir;
        q->dir = p;

        p->altura = max(altura_no(p-> esq), altura_no(p->dir)) + 1;
        q->altura = max(altura_no(q-> esq), altura_no(q->dir)) + 1;

        return q;
}

NO* rotacao_esq_dir(NO* p){
    p->esq = rotacao_esq(p->esq);
    return rotacao_dir(p);
}

NO* rotacao_dir_esq(NO* p){
    p->dir = rotacao_dir(p->dir);
    return rotacao_esq(p);
}

int FB(NO* p){
    if(p)
        return altura_no(p->esq) - altura_no(p->dir);
    return 0;
}

bool inserir_aux(NO** raiz, int dado){
    bool inseriu;
    if(*raiz == NULL){
        *raiz = criar_no(dado);
        return true;
    }
    else if(dado == (*raiz)->dado)
        return false;
    
    else if(dado < (*raiz)->dado){
        inseriu = inserir_aux(&(*raiz)->esq, dado);
    }
    else
        inseriu = inserir_aux(&(*raiz)->dir, dado);
    
    (*raiz)->altura = max(altura_no((*raiz)-> esq), altura_no((*raiz)->dir)) + 1;
    int fb = FB(*raiz);
    if(fb > 1){
        if (FB((*raiz)->esq) >= 0)
            *raiz = rotacao_dir(*raiz);
        else
            *raiz = rotacao_esq_dir(*raiz);
    } else if(fb < -1){
        if (FB((*raiz)->dir) <= 0)
            *raiz = rotacao_esq(*raiz);
        else
            *raiz = rotacao_dir_esq(*raiz);
    }
    return inseriu;
}

bool avl_inserir(AVL* A, int dado){
    bool inseriu = false;
    if(A){
        inseriu = inserir_aux(&A->raiz, dado);
    }
    return inseriu;
}

void ajusta_altura(NO** p){
    if(*p){

    }
}

void troca_maior_esq(NO* troca, NO* raiz, NO* anterior){
    if(troca->dir){
        troca_maior_esq(troca->dir, raiz, troca);
        //troca->altura = max(altura_no(troca-> esq), altura_no(troca->dir)) + 1;
    }
    raiz->dado = troca->dado;
    if(anterior == raiz)
        anterior->esq = troca->esq;
    else
        anterior->dir = troca->esq;
    free(troca);
    troca = NULL;
    //anterior->altura = max(altura_no(anterior-> esq), altura_no(anterior->dir)) + 1;
}

bool remover_aux(NO** raiz, int dado){
    if(raiz == NULL)
        return false;
    bool removeu;
    if(dado < (*raiz)->dado){
        removeu = remover_aux(&(*raiz)->esq, dado);
    } else if(dado > (*raiz)->dado){
        removeu = remover_aux(&(*raiz)->dir, dado);
    } else{
        if(!(*raiz)->dir || !(*raiz)->esq){
            NO* ptr = *raiz;
            if((*raiz)->esq){
                *raiz = (*raiz)->esq;
            } else {
                *raiz = (*raiz)->dir;
            }
            free(ptr);
            ptr = NULL;
        } else {
            troca_maior_esq((*raiz)->esq, *raiz, *raiz);
        }
        removeu = true;
    }

    if(removeu && *raiz){
        (*raiz)->altura = max(altura_no((*raiz)-> esq), altura_no((*raiz)->dir)) + 1;
        int fb = FB(*raiz);
        if(fb > 1){
            if (FB((*raiz)->esq) >= 0)
                *raiz = rotacao_dir(*raiz);
            else
                *raiz = rotacao_esq_dir(*raiz);
        } else if(fb < -1){
            if (FB((*raiz)->dir) <= 0)
                *raiz = rotacao_esq(*raiz);
            else
                *raiz = rotacao_dir_esq(*raiz);
        }
    }
    return removeu;
}

bool avl_remover(AVL* A, int dado){
    bool removeu = false;
    if(A){
        removeu = remover_aux(&(A->raiz), dado);
    }
    return removeu;
}

void imprimir_aux(NO* p){
    if(p){
        imprimir_aux(p->esq);
        printf("%d (%d) ", p->dado, FB(p));
        imprimir_aux(p->dir);
    }
}

void avl_imprimir(AVL* A){
    if(A){
        imprimir_aux(A->raiz);
        printf("\n");
    }
}

void apagar_no(NO** p){
    if(*p){
        apagar_no(&(*p)->esq);
        apagar_no(&(*p)->dir);
        free(*p);
        *p = NULL;
    }
}

void avl_apagar(AVL** A){
    if(*A){
        apagar_no(&(*A)->raiz);
        free(*A);
        *A = NULL;
    }
}