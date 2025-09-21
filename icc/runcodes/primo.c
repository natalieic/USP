#include <stdio.h>

int main(){
    long int q, n;
    scanf("%ld", &q);

    while(q>0){
        char p=1;
        scanf("%ld", &n);
        if(n>2 && n%2==0)
            p=0;
        else{
            for(int i=3; i*i<=n; i+=2){
                if(n%i==0){
                    p=0; break;
                }
            }
        }
        if(p)
            printf("Sim\n");
        else
            printf("Nao\n");
        q--;
    }
}