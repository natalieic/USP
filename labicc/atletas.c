
#include <stdio.h>

void bubbleSort(int pontos[], int posicao[], int n);

int main(){
    int n, i, pontos[100], posicao[100];

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &pontos[i]);
        posicao[i]=i+1;
    }
    bubbleSort(pontos, posicao, n);
    for(i=n-1; i>=0; i--){
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, pontos[i], posicao[i]);
    }
    return 0;
}

void bubbleSort(int pontos[], int posicao[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++) {
            if(pontos[j]<pontos[j+1]){
                temp=pontos[j];
                pontos[j]=pontos[j+1];
                pontos[j+1]=temp;
                temp=posicao[j];
                posicao[j]=posicao[j+1];
                posicao[j+1]=temp;
            }
        }
    }
}
