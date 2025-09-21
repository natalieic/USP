#include <stdio.h>

int main(){
    int n, x=0; char c;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf(" %c", &c);
        x^=1<<(c-97);
    }
    if((n%2==0 && x==0) || n%2==1 && ((x&(x-1))==0))
        printf("Sim\n");
    else
        printf("Nao\n");
}