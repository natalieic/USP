/* 
    Arquivo de implementação da Árvore Rubro-Negra Inclinada 
    à Esquerda (Left Leaning Red-Black Tree), referida como RBT. 
*/
#include "rbt.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no_ NO;

// Estrutura primária da Árvore Rubro-Negra (LLRBT)
struct rbt_{
    NO* raiz; // Contém um ponteiro para o nó raiz
};

// Definição da struct nó
struct no_{
    int dado;
    bool cor; // Preto = 0, Vermelho = 1
    NO *esq, *dir;
    // Ponteiros para os nós filhos esquerdo e direito
};


// Declaração das funções públicas e das internas

RBT* rb_criar(void);

void rb_apagar(RBT** T);
void apagar_no(NO** raiz);

bool rb_inserir(RBT* T, int dado);
NO* inserir_aux(NO* h, int dado);
NO* criar_no(int dado);

bool rb_remover(RBT* T, int dado);
NO* remover_aux(NO** h, int dado, bool* removeu);
void move_verm_esq(NO* h);
void move_verm_dir(NO* h);
void troca_menor_direita(NO* troca, NO* raiz);
NO* apaga_menor(NO* h);

bool rb_busca(RBT* T, int dado);
bool busca_no(NO* raiz, int dado);

void rb_imprimir(RBT* T);
void imprimir_no(NO* raiz);

RBT* rb_merge(RBT* T1, RBT* T2);
void merge_no(NO* h, RBT* T);

RBT* rb_comum(RBT* T1, RBT* T2);
void no_comum(NO* h, RBT* T2, RBT* T3);

bool Vermelho(NO* h);
NO* ajusta(NO* h);
NO* rotacao_dir(NO* h);
NO* rotacao_esq(NO* h);
void inverte(NO* h);


/* Essa função inicializa uma RBT e retorna um 
    ponteiro para a estrutura */
RBT* rb_criar(void){
    // Aloca a struct RBT
    RBT* T = (RBT*) malloc(sizeof(RBT));
    /* Se a memória foi alocada, inicializa o 
        ponteiro para a raiz como NULL */
    if(T != NULL){
        T->raiz = NULL;
    }
    /* Retorna o ponteiro ou NULL se a alocação 
        foi mal sucedida */
    return T;
}

/* Operação de inserção do inteiro 'dado' na árvore T. 
    Retora um booleano relativo ao êxito da inserção */
bool rb_inserir(RBT* T, int dado){
    if(T != NULL){
        // Chama a função auxiliar da inserção
        T->raiz = inserir_aux(T->raiz, dado);
        // A cor da raiz é sempre preto
        T->raiz->cor = 0;
        return true;
    }
    return false;
}

/* Função que realiza a inserção propriamente dita. 
    A primeira chamada recebe a raíz da árvore e a 
    partir daí, a função busca um local disponível 
    para a inserção. */
NO* inserir_aux(NO* h, int dado){
/* Se atingiu um ponteiro nulo, chama a função criar_no() 
    e retorna o endereço do nó criado */
    if(h == NULL)
        return criar_no(dado);

/* Se o valor já estiver presente na árvore, retorna o 
    nó atual e nenhuma modificação é feita na árvore */
    if(dado == h->dado)
        return h;

/* Chamada recursiva para a esquerda se o valor for menor 
    do que o do nó atual */
    if(dado < h->dado)
        h->esq = inserir_aux(h->esq, dado);

/* Chamada recursiva para a direita se o valor for maior  
    do que o do nó atual */
    if(dado > h->dado)
        h->dir = inserir_aux(h->dir, dado);

/* Ao final do processo, a função ajusta() faz o rebalanceamento 
    dos nós possivelmente afetados pela inserção recursivamente */
    return ajusta(h);
}

/* Função que cria e inicializa um nó com o valor fornecido */
NO* criar_no(int dado){
    NO* no = (NO*) malloc(sizeof(NO));
    if(no != NULL){
        no->dado = dado;
        no->cor = 1;
    // Aresta incidente de todo nó inserido é vermelha
        no->esq = NULL;
        no->dir = NULL;
    }
    return no;
}

/* Função que realiza o rebalanceamento de uma sub-árvore 
    com raiz em h segundo os critperios de uma LLRBT */
NO* ajusta(NO* h){
    if(h){
    /* Regras: 
        - Todo nó possuiu no máximo uma aresta vermelha, sempre 
        no filho esquerdo 
        - Todo filho nulo está à mesma distância negra da raiz
    */
    /* Se só o filho direito de h é vermelho, uma rotação de h 
        à esquerda resolve */    
        if(Vermelho(h->dir) && !Vermelho(h->esq))
            h = rotacao_esq(h);

    /* Se a aresta esquerda de h é vermelha, bem como a do seu 
        filho esquerdo (duas arestas esquerdas vermelhas 
        consecutivas), h deve ser rotacionado à direita */
        if(Vermelho(h->esq) && Vermelho(h->esq->esq))
            h = rotacao_dir(h);

    /* Se ambos filhos de h forem vermelhos, deve-se realizar uma 
        inversão em h */
        if(Vermelho(h->dir) && Vermelho(h->esq))
            inverte(h);
    }
    // Retorna o nó ajustado
    return h;
}

bool rb_remover(RBT* T, int dado){
    bool removeu = false;
    if(T != NULL){
        T->raiz = remover_aux(&T->raiz, dado, &removeu);
        T->raiz->cor = 0;
    }
    return removeu;
}

/* Função que realiza a remoção em si, recebe */
NO* remover_aux(NO* h, int dado, bool* removeu){
    if(h == NULL){
        return h;
    }
    if(dado < h->dado){
        move_verm_esq(h);
        h->esq = remover_aux(h->esq, dado, removeu);
    }
    else if(dado > h->dado){
        move_verm_dir(h);
        h->dir = remover_aux(h->dir, dado, removeu);
    }
    else{
        if(h->esq == NULL || h->dir == NULL){
            NO* ptr = h;
            if(h->esq == NULL)
                h = h->dir;
            else
                h = h->esq;
            free(ptr);
            ptr = NULL;
        } else{
            troca_menor_direita(h->dir, h);
            h->dir = apaga_menor(h->dir);
        }
        *removeu = true;
    }
    return ajusta(h);
}

void troca_menor_direita(NO* troca, NO* raiz){
    if(troca->esq == NULL)
        raiz->dado = troca->dado;
    else
        troca_menor_direita(troca->esq, raiz);
}

NO* apaga_menor(NO* h){
    if(h->esq == NULL){
        NO* ptr = h->dir;
        free(h);
        return ptr;
    }
    move_verm_esq(h);
    h->esq = apaga_menor(h->esq);
    return ajusta(h);
}

void move_verm_esq(NO* h){
    if(h->esq && !Vermelho(h->esq) && !Vermelho(h->esq->esq)){
        inverte(h);
        if(h->dir){
            if(Vermelho(h->dir->esq)){
                h->dir = rotacao_dir(h->dir);
                h = rotacao_esq(h);
                inverte(h);
            }
        }
    }
}

void move_verm_dir(NO* h){
    if(h->dir && !Vermelho(h->dir) && !Vermelho(h->dir->esq)){
        inverte(h);
        if(h->esq){
            if(Vermelho(h->esq->esq)){
                h = rotacao_dir(h->dir);
                inverte(h);
            }
        }
    }
}

/* Operação de busca do inteiro 'dado' na árvore T */
bool rb_busca(RBT* T, int dado){
    bool achou = false;
    if(T != NULL){
        // Chamada à função auxiliar busca_no()
        achou = busca_no(T->raiz, dado);
    }
    /* Retorna o resultado da busca ou 'falso' se 
        a árvore não existe */
    return achou;
}

bool busca_no(NO* raiz, int dado){
    if(raiz == NULL)
        return false;
    if(dado == raiz->dado)
        return true;
    if(dado < raiz->dado)
        return busca_no(raiz->esq, dado);
    else
        return busca_no(raiz->dir, dado);
}

void rb_imprimir(RBT* T){
    if(T != NULL){
        imprimir_no(T->raiz);
    }
}

void imprimir_no(NO* raiz){
    if(raiz != NULL){
        imprimir_no(raiz->esq);
        printf("%d, ", raiz->dado);
        imprimir_no(raiz->dir);
    }
}

RBT* rb_merge(RBT* T1, RBT* T2){
    RBT* T3 = rb_criar();
    if(T3){
        merge_no(T1->raiz, T3);
        merge_no(T2->raiz, T3);
    }
    return T3;
}

void merge_no(NO* h, RBT* T){
    if(h){
        rb_inserir(T, h->dado);
        merge_no(h->esq, T);
        merge_no(h->dir, T);
    }
}

RBT* rb_comum(RBT* T1, RBT* T2){
    RBT* T3 = rb_criar();
    if(T3){
        no_comum(T1->raiz, T2, T3);
    }
    return T3;
}

void no_comum(NO* h, RBT* T2, RBT* T3){
    if(h){
        if(rb_busca(T2, h->dado))
            rb_inserir(T3, h->dado);
        no_comum(h->esq, T2, T3);
        no_comum(h->dir, T2, T3);
    }
}

void rb_apagar(RBT** T){
    if(*T != NULL){
        apagar_no(&(*T)->raiz);
        free(*T);
        *T = NULL;
    }
}

void apagar_no(NO** raiz){
    if(*raiz != NULL){
        apagar_no(&(*raiz)->esq);
        apagar_no(&(*raiz)->dir);
        free(*raiz);
        *raiz = NULL;
    }
}

void inverte(NO* h){
    if(h){
        h->cor = !h->cor;
        if(h->esq)
            h->esq->cor = !h->esq->cor;
        if(h->dir)
            h->dir->cor = !h->dir->cor;
    }
}

NO* rotacao_dir(NO* h){
    if(h){
        NO* n = h->esq;
        h->esq = n->dir;
        n->dir = h;

        n->cor = h->cor;
        h->cor = 1;

        return n;
    }
    return h;
}

NO* rotacao_esq(NO* h){
    if(h){
        NO* n = h->dir;
        h->dir = n->esq;
        n->esq = h;

        n->cor = h->cor;
        h->cor = 1;

        return n;
    }

    return h;
}

bool Vermelho(NO* h){
    if(h == NULL)
        return 0;
    return (h->cor == 1);
}