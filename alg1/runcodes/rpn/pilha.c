#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

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
            (*pilha)->topo=aux->anterior;
            item_apagar(&((*pilha)->topo->item));
            free(aux);
            aux=(*pilha)->topo;
        }
        free(*pilha);
        *pilha=NULL;
    }

    return true;
}

/*bool pilha_apagar(PILHA** pilha){
    if (*pilha != NULL) {
        NO* aux = (*pilha)->topo;

        while (aux != NULL) {
            // Save the pointer to the previous node first
            NO* anterior = aux->anterior;

            // Delete the item associated with the current node
            delitem(&(aux->item));

            // Free the current node
            free(aux);

            // Move to the previous node
            aux = anterior;
        }

        // Finally, free the stack structure itself
        free(*pilha);
        *pilha = NULL;
    }

    return true;
}*/

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
    //delitem(&(pilha->topo)->item);

    NO* aux=pilha->topo;
    pilha->topo=(pilha->topo)->anterior;
    pilha->tamanho--;
    
    aux->anterior=NULL;
    free(aux);

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

    free(teste);
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
        //printf("%0x\n", *itemgetval(ptr->item));
        ptr=ptr->anterior;
    }

    return pilha->tamanho;
}