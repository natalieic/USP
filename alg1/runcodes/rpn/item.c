#include "item.h"
#include <stdlib.h>

struct item_{
    void* value;
    int id;
};

ITEM* item_criar(int id, void* value){
    ITEM* it;

    it=(ITEM*)malloc(sizeof(ITEM));

    if(it!=NULL){
        it->value=value;
        it->id=id;
        return it;
    }
    return NULL;
}

void item_apagar(ITEM** item){
    free(*item);
    *item=NULL;
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

bool item_set_chave(ITEM* item, int newid){
    if(item!=NULL){
        item->id=newid;
        return true;
    }
    return false;
}

int item_get_chave(ITEM* item){
    if(item!=NULL)
        return item->id;
}