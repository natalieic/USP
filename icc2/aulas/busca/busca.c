#include <stdio.h>

int main(void){

}

// Implementação com sentinela exige que o vetor seja declarado com tamaho maior.
int sequencial(int* vet, int n, int chave){
    vet[n]=chave;
    int i;
    for(i=0; v[i]!=chave; i++);
    if(i!=n)
        return i;
    return -1;
}

NO* encadeada(LISTA* lista, int chave){
    NO* ultimo=lista->fim;
    ultimo->proximo=criar_no(chave, NULL); // sentinela
    lista->fim=ultimo->proximo;
    NO* aux=lista->inicio;
    while(aux->chave!=chave)
        aux=aux->proximo;

    lista->fim=ultimo;

    if(aux->proximo!=NULL){
        apagar_no(&ultimo->proximo);
        return aux;
    }
    apagar_no(&ultimo->proximo);
    return NULL;
    
}

/* Tabela de índices:
    A tabela principal está ordenada pelas chaves e uma estrutura secundária armazena algumas das chaves, também ordenadas -- preferencialmente as chaves foram escolhidas em intervalos uniformes. Percorre-se primeiro o vetor de indices, quando encontra um maior do que a chave procurada, entra no endereço/indice indicado pela ultimo valor menor que a chave. A partir daí, já na tabela principal, realiza-se uma busca linear comum.
        Vantagens: muito menos comparações
        Desvantagens: espaço auxiliar para a tabela de indices, ambas estruturas tem que estar ordenadas. Cuidados com inserção e remoção:
        remoção deixa espaço vago, inserção pode usar um espaço vago ou ter que rearranjar todos os elementos a frente, e atualizar os indices que são fixos a um endereço.*/

typedef struct b_idx{
    int kindex, pos;
}bloco_indice

void cria_indice(bloco_indice* indice, int tam_indice, int* vet, int n){
    int gap=n/tam_indice, i=0;
    while(i<tam_indice){
        indice[i].kindex=vet[i*gap];
        indice[i].pos=i*gap;
        i++;
    }
}

int busca_indexada(int* vet, int n, bloco_indice* indice, int tam_indice, int chave){
    int pos=-1;
    for(int i=0; i<tam_indice-1; i++)
        if(chave>indice[i+1].kindex){
            pos=inidce[i].pos;
            break;
        }
    if(pos!=-1){
        while(chave<vet[pos])
            pos++;
        if(vet[pos]==chave)
            return pos;
    }

    return -1;
}