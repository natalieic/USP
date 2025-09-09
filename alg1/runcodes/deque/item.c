#include "item.h"
#include <stdlib.h>

struct item_{
    void* value;
    int id;
};

ITEM* item_criar(int chave, void* comp){
    ITEM* it;

    it=(ITEM*)malloc(sizeof(ITEM));

    if(it!=NULL){
        it->value=comp;
        it->id=chave;
        return it;
    }
    return NULL;
}

bool item_apagar(ITEM** item){
    if(*item==NULL)
        return false;
    free(*item);
    *item=NULL;
    return true;
}

bool item_set_dados(ITEM* item, void* value){
    if(item!=NULL){
        item->value=value;
        return true;
    }
    return false;
}

void* item_get_dados(ITEM* item){
    if(item!=NULL)
        return item->value;
    return NULL;
}

bool item_set_chave(ITEM* item, int chave){
    if(item!=NULL){
        item->id=chave;
        return true;
    }
    return false;
}

int item_get_chave(ITEM* item){
    if(item!=NULL)
        return item->id;
}