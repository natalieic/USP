#include "rbt.h"
#include <stdio.h>

int main(void){
    RBT *T1 = rb_criar(), *T2 = rb_criar();

    rb_inserir(T1, 10);
    rb_inserir(T1, 15);
    rb_inserir(T1, 20);
    rb_inserir(T1, 17);
    rb_inserir(T1, 25);
    rb_inserir(T1, 5);
    rb_inserir(T1, 12);
    printf("T1: ");
    rb_imprimir(T1);
    printf("\n");

    if(rb_remover(T1, 15)){
        printf("\nT1: ");
        rb_imprimir(T1);
        printf("\n");
    }

    // rb_inserir(T2, 9);
    // rb_inserir(T2, 15);
    // rb_inserir(T2, 20);
    // rb_inserir(T2, 11);
    // rb_inserir(T2, 7);
    // rb_inserir(T2, 21);
    // printf("T2: ");
    // rb_imprimir(T2);
    // printf("\n");

    // RBT* T3 = rb_merge(T1, T2);
    // printf("União: ");
    // rb_imprimir(T3);
    // printf("\n");


    // rb_apagar(&T1);
    // rb_apagar(&T2);
    // rb_apagar(&T3);
    
}