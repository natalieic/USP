#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "item.h"

float rpn(char* sequencia){
    PILHA* pilha=pilha_criar();
    float result=0, *val, n1, n2, *resptr;

    for(int i=0; sequencia[i]!='\0'; i++){

        if(sequencia[i]>='0' && sequencia[i]<='9'){
            val=malloc(sizeof(float));
            *val=sequencia[i]-'0';
            pilha_empilhar(pilha, item_criar(i, val));
        }
        else{
            if(!pilha_vazia(pilha))
                n2=*(float*)item_get_dados(pilha_desempilhar(pilha));
                
            if(!pilha_vazia(pilha))
                n1=*((float*)item_get_dados(pilha_desempilhar(pilha)));

                //printf("n1 %f\n", n1);
                //printf("n2 %f\n", n2);

            switch(sequencia[i]){
                case '+':
                    result=n1+n2; break;
                case'-':
                    result=n1-n2; break;
                case '*':
                    result=n1*n2; break;
                case'/':
                    result=n1/n2; break;
            }
            resptr=malloc(sizeof(float));
            *resptr=result;
            pilha_empilhar(pilha, item_criar(i, resptr));
            //printf("empilhou %f\n", result);
        }

    }
    //printf("saiu\n");
    //pilha_apagar(&pilha);
    //printf("pilha\n");

    return result;
}


int main(void){
    char seq[101];

    scanf(" %s", seq);

    printf("%.2f\n", rpn(seq));

    return 0;
}