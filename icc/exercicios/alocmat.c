
#include <stdio.h>
#include <stdlib.h>


int main(void){
    int l, c;
    scanf("%d %d", &l, &c);
// JEITO 3:
/*
    double *p;
    if((p=(double*)malloc(l*c*sizeof(double)))==NULL){
        printf("Erro na alocação da matriz.\n");
        exit(1);
    }
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++)
            scanf("%lf", &(p[i*c+j]));
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++)
            printf("%lf ", p[i*c+j]);
        printf("\n");
    }
    free(p);
    return 0;
*/

//JEITO 2:
/*
double **p;
    if((p=(double**)malloc(l*sizeof(double*)))==NULL){
            printf("Erro na alocação da matriz.\n");
            exit(1);
    }
    for(int i=0; i<l; i++){
        if((p[i]=(double*)malloc(c*sizeof(double)))==NULL){
            printf("erro");
            exit(1);
        };
    }
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++)
            scanf("%lf", p[i]+j);
    }
*/

//JEITO 1
}