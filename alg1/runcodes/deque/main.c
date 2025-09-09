#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    DEQUE* d=deque_criar();
    //int *e1=malloc(sizeof(int)), *e2=malloc(sizeof(int)), *e3=malloc(sizeof(int)), *e4=malloc(sizeof(int));
    int e1, e2, e3, e4;

    scanf("%d %d %d %d", &e1, &e2, &e3, &e4);

    deque_inserir_inicio(d, item_criar(e1, &e1));
    deque_inserir_inicio(d, item_criar(e2, &e2));
    deque_inserir_fim(d, item_criar(e3, &e3));
    deque_inserir_fim(d, item_criar(e4, &e4));

    printf("primeiro: %d, ultimo: %d\n", *(int*)item_get_dados(deque_primeiro(d)), *(int*)item_get_dados(deque_ultimo(d)));
    /*
    deque_remover_fim(d);
    deque_remover_inicio(d);

    int z=*(int*)item_get_dados(deque_primeiro(d));
    printf("segundo: %d\n", z);

    *(int*)item_get_dados(deque_ultimo(d));
    printf("checkpoint 1\n");

    int y=*(int*)item_get_dados(deque_ultimo(d));
    printf("checkpoint 2\n");
    printf("terceiro: %d\n", y);

    printf("novo primeiro: %d, novo ultimo: %d\n", *(int*)item_get_dados(deque_primeiro(d)), *(int*)item_get_dados(deque_ultimo(d)));
    */
    deque_remover_fim(d);
    deque_remover_inicio(d);
    

   printf("%d\n", *(int*)item_get_dados(deque_primeiro(d)));
   printf("%d\n", *(int*)item_get_dados(deque_ultimo(d)));

   printf("%d %d\n", *(int*)item_get_dados(deque_primeiro(d)), *(int*)item_get_dados(deque_ultimo(d)));
    
    deque_apagar(&d);

    return 0;
}