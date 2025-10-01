
#include <stdio.h>

void fill(int n, int m, char mapa[20][20]); //preenche os espaços da plateia com "o".
void plateia(int n, int m, char mapa[20][20]); //lê a matriz de entrada e chama a função xo.
void xo(int n, int m, int a, int b, char mapa[20][20]); //substitui por x os lugares onde Zé não pode sentar.


int main(){
    int n, m, o=0; //n linhas e m colunas
    char mapa[20][20];

    scanf("%d %d", &n, &m);
    fill(n, m, mapa);
    plateia(n, m, mapa);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mapa[i][j]=='o')
                o++;
        }
    }
    if(o){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
    } else
        printf("Eh um dia triste para os mono Yasuo\n");
}   

void fill(int n, int m, char mapa[20][20]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            mapa[i][j]='o';
    }
}

void xo(int n, int m, int a, int b, char mapa[20][20]){
    for(int j=0; j<m; j++)
        mapa[a][j]='x';
    
    for(int i=0; i<n; i++)
        mapa[i][b]='x';
}

void plateia(int n, int m, char mapa[20][20]){
    char p[20][20];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &p[i][j]);
            if(p[i][j]=='c')
                xo(n, m, i, j, mapa);
            else if(p[i][j]=='f')
                mapa[i][j]='x';
        }
    } 
}