#include <stdio.h>

int main(void){
    int a, b, *p, *q;

    scanf("%d %d", &a, &b);

    p=&a;
    *q=*p;
    a=b;
    b=*q;

    printf("%d %d\n", a, b);

    return 0;
}