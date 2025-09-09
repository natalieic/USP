#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main (void){
    FILA* f=fila_criar();
    int n, *dado;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        dado=malloc(sizeof(int));
        scanf("%d", dado);
        fila_inserir(f, item_criar(i, dado));
    }

    printf("Item: %d\n", *(int*)item_get_dados(fila_remover(f)));
    fila_inverter(f);
    printf("Item: %d\n", *(int*)item_get_dados(fila_remover(f)));

    fila_apagar(&f);

    if(item_get_dados(fila_remover(f))==NULL)
         printf("Fila vazia!\n");

    return 0;
}