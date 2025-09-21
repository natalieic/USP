#include <stdio.h>

int main (){
    char c='a';
    int n=0, l=0;
    while (c!='@'){
        scanf("%c", &c);
        if (c>47 && c<58){
            n++;
        }
        if (c>96 && c<123){
            l++;
        }
    }
    printf("%d letras e %d numeros\n", l, n);
}