#include <stdio.h>

void ler(int mat[15][15], int dim);
void print(int mat[15][15], int dim);
int diag(int mat[15][15], int dim);
int prodp(int m1[15][15], int m2[15][15], int dim, int a, int b);

int main(){
    int n, m, m1[15][15], m2[15][15], m3[15][15];

    scanf("%d %d", &n, &m);
    ler(m1, n); ler(m2, m);
    printf("Matrizes:\n");
    print(m1, n); print(m2, m);

    if(diag(m1, n))
        printf("A matriz 1 eh diagonal\n");
    else
        printf("A matriz 1 nao eh diagonal\n");

    if(diag(m2, m))
        printf("A matriz 2 eh diagonal\n");
    else
        printf("A matriz 2 nao eh diagonal\n");
    
    if(n==m){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                m3[i][j]=prodp(m1, m2, n, i, j);
            }
        }
        printf("Matriz multiplicada:\n");
        print(m3, n);
    }else
        printf("Matrizes de tamanho incompativel\n");
}

void ler(int mat[15][15], int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++)
            scanf("%d", &mat[i][j]);
    }
}

void print(int mat[15][15], int dim){
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int diag(int mat[15][15], int dim){
    int d=1;
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            if(i==j && mat[i][j]==0)
                d=0;
            if(i!=j && mat[i][j]!=0)
                d=0;
        }  
    }
    return d;
}

int prodp(int m1[15][15], int m2[15][15], int dim, int a, int b){
    int s=0;
    for(int i=0; i<dim; i++)
            s+=m1[a][i]*m2[i][b];
    return s;
}