#include "stack.h"
#include <stdlib.h>

struct stack_{
    item* array[MAXSIZE];
    int size;
};

stack* newstack(void){
    stack* s;

    s=(item*)malloc(sizeof(stack));
    s->size=0;

    return s;
}

void delstack(stack** s){
    for(int i=0; i<s->size; i++)
        delitem(((*s)->array)+i);
    
    delitem(&top);
    free(*s);
    *s=NULL;
}

bool stacking(item* item, stack* s){
    if(s!=NULL&&!stackfull(s)){
        s->array[size]=item;
        size++;
        s->top=item;
        return true;
    }

    return false;
}

item* unstack(stack* s){
    if(s!=NULL&&!stackempty(s)){
        item* i=stacktop(s);
        s->size--;
        delitem(s->array+size);
        return i;
    }

    return NULL;
}

item* stacktop(stack* s){
    if(s!=NULL)
        return s->array[size-1];

    return NULL;
}

bool stackempty(stack* s){
    return !s->size;
}

bool stackfull(stack* s){
    if(size==MAXSIZE)
        return true;
    
    return false;
}

int stacksize(stack* s){
    if(s!=NULL)
        return s->size;

    return -1;
}

void stackprint(stack* s){
    if(s!=NULL){
        for(int i=s->size-1; i>=0; i--)
            printf("%d\n", itemgetval(s->array+i));
    }
}

bool stackrev(stack* s){
    if(s==NULL)
        return false;

    item* aux;
    for(int i=0, j=s->size-1; j>s->size/2; i++; j--){
        aux=s->array[j];
        s->array[j]=s->array[i];
        s->array[i]=aux;
    }

    for(int i=0; i<s->size/2; i++){
        aux=stacktop(s)-i;
        s->array[s->size-1-i]=s->array[i];
        s->array[i]=aux;
    }
}