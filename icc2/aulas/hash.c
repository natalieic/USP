#define VAZIO -1
#define REMOVED -2

hash_t tabela[TAM_TABELA]

int h(int chave){
    return chave%TAM_TABELA
}

void inserir(int chave, int valor){
    int idx=h(chave);
    int novoidx=idx;

    for(int i=0; i<TAM_TABELA; i++){
        if(tabela[idx].chave==VAZIO||tabela[idx].chave==REMOVED){
            tabela[idx].chave=chave;
            tabela[idx].valor=valor;
        }
    }
}

int busca(int chave){
    int idx=h(chave);

    for(int i=0; i<TAM_TABELA; i++){
        if(tabela[idx].chave==chave)
            return tabela[idx].valor;
        if(tabela[idx].chave==EMPTY)
            break;
        else{

        }
    }
}