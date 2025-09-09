#ifndef ARVORE_BINARIA_H
    #define ARVORE_BINARIA_H
    #include "../item/item.h"
    #define ERRO -32000
    #define FILHO_ESQ 0
    #define FILHO_DIR 1

    typedef struct arv_bin AB;
 
    AB *ab_criar(void);
    bool ab_inserir (AB *T, ITEM *item, int lado, int chave);
    void ab_imprimir (AB *T);
    int ab_profundidade(AB* T);
    void ab_apagar_arvore(AB **T);

    int ab_qtd_elementos(AB* T);
    int ab_maior(AB* T);
    int ab_soma(AB* T);

#endif