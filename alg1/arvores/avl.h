#ifndef AVL_H
    #define AVL_H
    #include <stdbool.h>

    typedef struct avl_ AVL; 

    AVL* avl_criar(void);
    void avl_apagar(AVL **A);
    bool avl_inserir(AVL *A, int dado);
    bool avl_remover(AVL *A, int dado);
    bool avl_busca(AVL *A, int dado); 
    void avl_imprimir(AVL *A);

#endif 