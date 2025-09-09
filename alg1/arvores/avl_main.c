#include "avl.h"
#include <stdio.h>

int main(void){
    AVL* A = avl_criar();
    int fila[9] = {10, 7, 20, 15, 17, 25, 30, 5, 1};

    for(int i = 0; i < 9; i++){
        avl_inserir(A, fila[i]);
        avl_imprimir(A);
    }

    
    
    avl_remover(A, 8);
    avl_imprimir(A);
    avl_apagar(&A);
    if(!A){
        printf("deleted");
    }
    
}