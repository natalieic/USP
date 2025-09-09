#include <stdio.h>
#include "litem.h"

int main(void){
    item* it;
    char val[13];

    //for(int i=0; i<10; i++){
        it=newitem(NULL, 0);
        scanf(" %s", val);
        itemsetval(it, &val);
    //}

    //for(int i=0; i<10; i++){
        printf("item %d: %s\n", itemgetid(it), (char*)itemgetval(it));
        delitem(&it);
    //}

    return 0;
}