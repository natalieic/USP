#include <stdio.h>

int main (){

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a!=0 && b!=0 && c!=0 && d!=0){
        if (a==b && b==c && c==d && d==a)
            printf("quadrado!\n");
        else if (a!=b && a==c && c!=d && b==d)
            printf("retangulo!\n");
        else
            printf("nenhum!\n");
    } else
        printf("nenhum!\n");
}