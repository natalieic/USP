#include <stdio.h>

void ler(float mat[100][25], int n, int m); //lê uma matriz onde cada linha representa um aluno e cada coluna uma nota de um exercício
void aluno(float mat[100][25], int n, int m); //calcula a média de notas por aluno
void exerc(float mat[100][25], int n, int m);//calcula a média de notas por exercício e ordena decrescentemente

int main(){
    int n, m; float mat[100][25];

    scanf("%d %d", &n, &m);
    ler(mat, n, m);
    aluno(mat, n, m);
    printf("\n");
    exerc(mat, n, m);

}

void ler(float mat[100][25], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            scanf("%f", &mat[i][j]);
    }
}

void aluno(float mat[100][25], int n, int m){
    for(int i=0; i<n; i++){
        float soma=0;
        for(int j=0; j<m; j++)
            soma+=mat[i][j];
        soma/=m;
        printf("Media do aluno %d = %.2f : ", i+1, soma);
        if((soma)>=5)
            printf("Aprovado\n");
        else
            printf("Reprovado\n");
    }
}

void exerc(float mat[100][25], int n, int m){
    float v[25]={0}, temp;

    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++)
            mat[0][j]+=mat[i][j];
        v[j]=mat[0][j]/n;
    }
    for(int i=0; i<m-1; i++){
        for(int j=0; j<m-i-1; j++){
            if(v[j]<v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    for(int i=0; i<m; i++)
        printf("%.2f ", v[i]);
    scanf("%*c");
    printf("\n");
}