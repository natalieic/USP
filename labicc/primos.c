#include <stdio.h>

int main(){
    int a, b, i=2;
    scanf("%d %d", &a, &b);

    if(a>b){
        a=a-b;
        b=b+a;
        a=b-a;
    }
    while(i<=a/2 && a<=b){
        if(a%i==0){
            a++; i=2;
            continue;
        }
        i++;
    }
    if(a>b || a==0 && b==0){
        printf("nenhum primo no intervalo\n");
        return 0;
    }
    else
        printf("menor primo: %d\n", a+(a==1));
   
    while(i<=b/2 && b>=a){
        if(b%i==0){
            b--; i=2;
            continue;
        }
        i++;
    }
    printf("maior primo: %d\n", b);
}