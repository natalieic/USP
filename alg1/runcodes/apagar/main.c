#include "../../item/item.h"
#include "fila.h"
#include <stdio.h>

int main(void){
    int n, elemento;
    FILA* fila=fila_criar();

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &elemento);
        fila_inserir(fila, item_criar(elemento, &elemento));
    }
    // for(int i=0; i<n; i++){
    //     printf("%d", &elemento);
    //     fila_inserir(fila, item_criar(elemento, &elemento));
    // }

    printf("%d\n", *(int*)item_get_dados(fila_frente(fila)));

    fila_apagar(&fila);
    if(fila==NULL)
        printf("fila==NULL\n");
    if(fila_frente(fila)==NULL)
        printf("frente da fila ta nul\n");
    if((int*)item_get_dados(fila_frente(fila))==NULL);
        printf("dados do item da frente apontam pra nul\n");
    return 0;
}