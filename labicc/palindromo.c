#include <stdio.h>

void palind(char *mat, int t);

int main(){
    int n, i; char c[50];

    scanf("%d", &n);
    while(n>0){
        *c='\0';
        scanf("%*c");
        for(i=0; i<50; i++){
            scanf("%[^\n]", &c[i]);
            if(c[i]=='\0'){
                i-=1;
                break;
            }
        }
        palind(c, i);
    n--;
    }
    return 0;
}

void palind(char *mat, int t){
    int u=0, p=0, v=t;
    while(u!=v && u<v){
        if(mat[u]!=mat[v]){
            p=1;
            break;
        }
        u++; v--;
    }
    for(int i=0; i<t+1; i++){
        printf("%c", mat[i]);
    }
    if(p)
        printf(" nao eh um palindromo\n");
    else
        printf(" eh um palindromo\n");
}