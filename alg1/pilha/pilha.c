#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ NO;
struct pilha_{
    NO* topo;
    int tamanho;
};

struct no_{
    ITEM* item;
    NO* anterior;
};

PILHA* pilha_criar(void){
    PILHA* p;

    p=(PILHA*)malloc(sizeof(PILHA));

    p->topo=NULL;
    p->tamanho=0;

    return p;
}

bool pilha_apagar(PILHA** pilha){
    if(*pilha!=NULL){
        NO* aux=(*pilha)->topo;

        while(aux!=NULL){
            item_apagar(&((*pilha)->topo->item));
            aux=(*pilha)->topo;
            (*pilha)->topo=(*pilha)->topo->anterior;
            (*pilha)->topo->anterior=NULL;
            free(aux);
        }
    }

    return true;
}

bool pilha_empilhar(PILHA* pilha, ITEM* item){
    if(pilha_cheia(pilha))
        return false;

    NO* no=(NO*)malloc(sizeof(NO));
    no->item=item;
    no->anterior=pilha->topo;
    pilha->topo=no;
    pilha->tamanho++;

    return true;
}

ITEM* pilha_desempilhar(PILHA* pilha){
    if(pilha_vazia(pilha))
        return NULL;

    ITEM* it=(pilha->topo)->item;
    item_apagar(&(pilha->topo)->item);

    NO* aux=pilha->topo;
    pilha->topo=(pilha->topo)->anterior;
    pilha->tamanho--;
    
    aux->anterior=NULL;

    return it;
}

bool pilha_vazia(PILHA* pilha){
    if(pilha!=NULL||pilha->tamanho)
        return false;

    return true;
}

bool pilha_cheia(PILHA* pilha){
    NO* teste=(NO*)malloc(sizeof(NO));
    
    if(teste==NULL)
        return true;

    return false;
}

int pilha_tamanho(PILHA* pilha){
    return pilha->tamanho;
}

int pilha_print(PILHA* pilha){
    if(pilha_vazia(pilha))
        return 0;

    NO* ptr=pilha->topo;

    while(ptr!=NULL){
        printf("[%d] ", item_get_chave(ptr->item));
        ptr=ptr->anterior;
    }
    printf("\n");

    return pilha->tamanho;
}

NO* inverte(PILHA* pilha, NO* no){
    if(no->anterior->anterior==NULL){
        pilha->topo=no->anterior;
        no->anterior->anterior=no;
        return no;
    }
    inverte(pilha, no->anterior);
    no->anterior->anterior=no;
    return no;
}

bool pilha_inverter(PILHA* pilha){
    if(pilha==NULL)
        return false;
    if(pilha->tamanho>1){
        NO* aux=pilha->topo;
        inverte(pilha, pilha->topo);
        aux->anterior=NULL;
    }

    return true;
}