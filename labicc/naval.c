#include <stdio.h>

void ler(char mat[26][26], int n);
void coord(char mat[26][26], char a, int b);
void print(char mat[26][26], int n);

int main(){
    int n, i, c2;
    char tab[26][26], c1;

    scanf("%d", &n);
    ler(tab, n);
    scanf("%d", &i);
    while(i>0){
        scanf(" %c%d", &c1, &c2);
        coord(tab, c1, c2);
        i--;
    }
    print(tab, n);
}

void ler(char mat[26][26], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            scanf(" %c", &mat[i][j]);
    }
}

void coord(char mat[26][26], char a, int b){
    if(mat[a-65][b-1]=='N'){
        printf("acerto!\n");
        mat[a-65][b-1]='X';
    } else
        printf("erro!\n");
}

void print(char mat[26][26], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }
}