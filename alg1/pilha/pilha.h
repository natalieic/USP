#ifndef PILHA_H
    #define PILHA_H

    #include "../item/item.h"

    typedef struct pilha_ PILHA;
    typedef struct no_ NO;

    PILHA* pilha_criar(void);
    bool pilha_apagar(PILHA** pilha);
    bool pilha_empilhar(PILHA* pilha, ITEM* item);
    ITEM* pilha_desempilhar(PILHA* pilha);
    bool pilha_vazia(PILHA* pilha);
    bool pilha_cheia(PILHA* pilha);
    int pilha_tamanho(PILHA* pilha);
    int pilha_print(PILHA* pilha);
    bool pilha_inverter(PILHA* pilha);



#endif