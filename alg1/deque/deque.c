#include "deque.h"
#include <stdlib.h>

typedef struct no_{
    ITEM* item;
    NO *anterior, *proximo;
}NO;

struct deque_{
    NO *inicio, *fim;
    int tamanho;
};

DEQUE* deque_criar(void){
    DEQUE* deque=malloc(sizeof(DEQUE));
    if(deque!=NULL){
        deque->inicio=NULL;
        deque->fim=NULL;
        deque->tamanho=0;
    }

    return deque;
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item){
    NO* no=malloc(sizeof(NO));
    if(deque==NULL||no==NULL)
        return false;
    
    no->proximo=deque->inicio;
    no->anterior=NULL;
    no->item=item;
    if(deque->inicio!=NULL)
        deque->inicio->anterior=no;
    deque->inicio=no;
    deque->tamanho++;

    if(deque->tamanho==1)
        deque->fim=deque->inicio;

    return true;
}