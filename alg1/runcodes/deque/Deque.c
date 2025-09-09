#include "Deque.h"
#include "item.h"
#include <stdlib.h>

struct deque_{
    ITEM* array[MAX_TAMANHO];
    int inicio, fim, tamanho;
};

DEQUE* deque_criar(void){
    DEQUE* deque=calloc(1, sizeof(DEQUE));
    deque->inicio=0;
    deque->fim=0;
    deque->tamanho=0;
    
    return deque;
}

void deque_apagar(DEQUE** deque){
    if(*deque==NULL)
        return;
    
    for(int i=0; i<MAX_TAMANHO; i++){
        if((*deque)->array[i]!=NULL)
            item_apagar((*deque)->array+i);
    }
    free(*deque);
    *deque=NULL;
}

bool deque_inserir_inicio(DEQUE* deque, ITEM* item){
    if(deque==NULL||deque->tamanho==MAX_TAMANHO)
        return false;

    deque->inicio=(deque->inicio-1+MAX_TAMANHO)%MAX_TAMANHO;
    deque->array[deque->inicio]=item;
    deque->tamanho++;

    return true;
}

bool deque_inserir_fim(DEQUE* deque, ITEM* item){
    if(deque==NULL||deque->tamanho==MAX_TAMANHO||deque->array[deque->fim]!=NULL)
        return false;
    deque->array[deque->fim]=item;
    deque->fim=(deque->fim+1+MAX_TAMANHO)%MAX_TAMANHO;
    deque->tamanho++;

    return true;
}

ITEM* deque_remover_inicio(DEQUE* deque){
    if(deque==NULL||deque->tamanho==0)
        return NULL;

    ITEM* item=item_criar(item_get_chave(deque->array[deque->inicio]), item_get_dados(deque->array[deque->inicio]));
    item_apagar(deque->array+deque->inicio);
    deque->inicio=(deque->inicio+1)%MAX_TAMANHO;
    deque->tamanho--;

    return item;
}


ITEM* deque_remover_fim(DEQUE* deque){
    if(deque==NULL||deque->tamanho==0)
        return NULL;
    deque->fim=(deque->fim-1+MAX_TAMANHO)%MAX_TAMANHO;
    ITEM* item=item_criar(item_get_chave(deque->array[deque->fim]), item_get_dados(deque->array[deque->fim]));
    item_apagar(deque->array+deque->fim);
    deque->tamanho--;

    return item;
}

ITEM* deque_primeiro(DEQUE* deque){
    if(deque==NULL||deque->tamanho==0)
        return NULL;
    return deque->array[deque->inicio];
}

ITEM* deque_ultimo(DEQUE* deque){
    if(deque==NULL||deque->tamanho==0)
        return NULL;
    return deque->array[(deque->fim-1+MAX_TAMANHO)%MAX_TAMANHO];
}

int deque_contar(DEQUE* deque){
    if(deque==NULL)
        return ERRO;
    return deque->tamanho;
}

bool deque_vazia(DEQUE* deque){
    if(deque==NULL)
        return true;
    return deque->tamanho==0;
}

bool deque_cheia(DEQUE* deque){
    if(deque->tamanho==MAX_TAMANHO||deque==NULL)
        return true;
    return false;
}