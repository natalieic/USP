#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    /*Escreva uma função double(double x, int n) que calcule x^n.*/
/*
double expo(double x, int n){
    if(n==0)
        return 1;
    double r=x;
    for(int i=0; i<n-1; i++)
        r*=x;
    return r;
}

int main(){
    int n; double x;
    printf("Base: ");
    scanf("%lf", &x);
    printf("Expoente: ");
    scanf("%d", &n);
    printf("%lf^%d = %lf", x, n, expo(x, n));
}
*/

    /*Escreva uma função que recebe uma string e um número inteiro x como parâmetros. A função deve escrever a string na tela x vezes.*/
/*
void xstring(char *string, int x){
    while(x>0){
        printf("%s\n", string);
        x--;
    }

}

int main (void){
    char temp[100];
    int x;

    fgets(temp, 100, stdin);
    scanf("%d", &x);

    int tam=strlen(temp);
    temp[tam-1]='\0';
    char *str=(char*)malloc(tam);
    strcpy(str, temp);

    xstring(str, x);
    
    free(str);

    return(0);
}
*/

    /*Escreva uma função que realize a ordenação de um vetor de 10 elementos inteiros em ordem não decrescente (podem haver números repetidos).
    Exemplo, o vetor {1, 5, 6, 2, 8, 9, 2, 4, 4, 3} deve ficar {1, 2, 2, 3, 4, 4, 5, 6, 8, 9}.*/
/*
int* ordena(int *vet){
    int temp;
    for(int i=0; i<10-1; i++){
        for(int j=0; j<10-1-i; j++){
            if(vet[j]>vet[j+1]){
                temp=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=temp;
            }
        }
    }
    return vet;
}

int main(){
    int vetor[10];

    for(int i=0; i<10; i++){
        scanf("%d", &vetor[i]);
    }

    ordena(vetor);
    printf("{");
    for(int i=0; i<10; i++)
        printf("%d, ", vetor[i]);
    printf("\b\b}");

    return 0;
}
*/
