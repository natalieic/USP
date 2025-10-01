#include <stdio.h>
#include <stdlib.h>

int missing(char *vet, int n);

int main(void){
    int n, x;
    char *vet;

    scanf("%d", &n);

    vet=(char*)malloc(n);

    for(int i=0; i<n-1; i++){
        scanf("%d", &x);
        vet[x]=1;
    }

    printf("Numero desaparecido: %d\n", missing(vet, n));

    return 0;
}

int missing(char *vet, int n){
    int i;
    for(i=1; i<n; i++){
        if(!vet[i])
            break;
    }

    return i;
}

/*
    ESSE NÃO USA VETOR

int missing(int n);
int soma(int n);

int main(void){
    int n;

    scanf("%d", &n);

    printf("Numero desaparecido: %d\n", missing(n));
    
    return 0;
}

int soma(int n){
    int total=0;

    while(n>0){
        total+=n;
        n--;
    }

    return total;
}

int missing(int n){
    int s, sum=0;

    for(int i=0; i<n-1; i++){
        scanf("%d", &s);
        sum+=s;
    }

    return(soma(n)-sum);
}
*/