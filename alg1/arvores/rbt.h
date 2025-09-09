#ifndef RBT_H
    #define RBT_H
    #include <stdbool.h>

    typedef struct rbt_ RBT;

    RBT* rb_criar(void);
    void rb_apagar(RBT** T);
    bool rb_inserir(RBT* T, int dado);
    bool rb_remover(RBT* T, int dado);
    bool rb_busca(RBT* T, int dado);
    void rb_imprimir(RBT* T);
    RBT* rb_merge(RBT* T1, RBT* T2);
    RBT* rb_comum(RBT* T1, RBT* T2);

#endif