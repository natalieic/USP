#include "lista.h"

typedef struct no_ NO;
struct no_{
    ITEM* item;
    NO *anterior, *proximo;
}

strcut lista_{
    NO *inicio, *fim;
    int tamanho;
    bool ordenada;
};

bool lista_inserir(LISTA* lista, ITEM* item){
    NO* n=malloc(sizeof(NO));
    if(lista==NULL||n==NULL)
        return false;
    n->item=item;
    if(item_get_chave(item)>item_get_chave(lista->fim)){
        lista->fim->proximo=n;
        n->anterior=lista->fim;
        n->proximo=NULL;
        lista->fim=n;
    }
    if(lista->inicio==NULL){
        lista
    }

}