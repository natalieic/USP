#include "litem.h"
#include <stdlib.h>

struct item_{
    void* value;
    int id;
};

item* newitem(void* value, int id){
    item* it;

    it=(item*)malloc(sizeof(item));

    if(it!=NULL){
        it->value=value;
        it->id=id;
        return it;
    }
    return NULL;
}

void delitem(item** item){
    free(*item);
    *item=NULL;
}

bool itemsetval(item* item, void* value){
    if(item!=NULL){
        item->value=value;
        return true;
    }
    return false;
}

void* itemgetval(item* item){
    if(item!=NULL)
        return item->value;
    return NULL;
}

bool itemsetid(item* item, int newid){
    if(item!=NULL){
        item->id=newid;
        return true;
    }
    return false;
}

int itemgetid(item* item){
    if(item!=NULL)
        return item->id;
}