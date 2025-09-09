#include "Pilha.h"

bool balanceada(char *sequencia){
    PILHA *p;
    p=pilha_criar();

    for(int i=0; sequencia[i]!='\0'; i++){
        if(sequencia[i]=='('||sequencia[i]=='['||sequencia[i]=='{')
            pilha_empilhar(p, item_criar(i, sequencia+i));

        else{
            if(!pilha_vazia(p)){
                int d=sequencia[i]-*((char*)item_get_dados(pilha_topo(p)));

                if(d==1||d==2)
                    pilha_desempilhar(p);
                else{
                    break;
                }
            }else{
                pilha_apagar(&p);
                return false;
            }
        }
    }

    bool vazia=pilha_vazia(p);
    pilha_apagar(&p);

    return vazia;
}