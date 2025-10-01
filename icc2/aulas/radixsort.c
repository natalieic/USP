/*
    O(n*m), onde m é o número de dígitos do maior valor => O(n).
    Estável, o primeiro é adicionado na lista e removido primeiro.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct no_ no;

struct no_{
    no* proximo;
    int valor;
};

typedef struct fila_{
    no *inicio, *fim;
}fila;

fila* criar(void){
    fila* f=malloc(sizeof(fila));
    if(f!=NULL){
        f->inicio=NULL;
        f->fim=NULL;
    }
    return f;
}

void inserir(fila *f, int valor){
    no *aux=malloc(sizeof(no));
    aux->valor=valor;
    aux->proximo=NULL;

    if(f->inicio==NULL)
        f->inicio=aux;
    else
        f->fim->proximo=aux;
    f->fim=aux;
}

int remover(fila *f){
    if(f->inicio==NULL)
        return -9999999;
    no *aux=f->inicio;
    f->inicio=f->inicio->proximo;
    int valor=aux->valor;
    free(aux);

    return valor;
}

int vazia(fila* f){
    if(f->inicio==NULL)
        return 1;
    return 0;
}

void apagar(fila* f){
    no* aux;
    while(f->inicio!=NULL){
        aux=f->inicio;
        f->inicio=f->inicio->proximo;
        free(aux);
    }
}

int digito(int num, int pos){
    for(int i=0; i<pos; i++)
        num/=10;

    return num%10;
}

int main(void){
    int v[]={3, 65, 125, 77, 9, 452, 2, 9, 11, 7754};
    int maior=-1, maxdig;
    for(int i=0; i<10; i++){
        if(v[i]>maior)
            maior=v[i];
    }

    if(maior>9)
        maxdig=2;
    if(maior>99)
        maxdig=3;
    if(maior>999)
        maxdig=4;
    if(maior>9999)
        maxdig=5;

    fila *f[10];
    for(int i=0; i<10; i++){
        f[i]=criar();
    }

    for(int pos=0; pos<maxdig; pos++){
        for(int i=0; i<10; i++){
            inserir(f[digito(v[i], pos)], v[i]);
        }
        int k=0;
        for(int i=0; i<10; i++){
            while(!vazia(f[i])){
                v[k++]=remover(f[i]);
            }
        }
    }

    for(int i=0; i<10; i++)
        apagar(f[i]);

    for(int i=0; i<10; i++)
        printf("%d ", v[i]);
}