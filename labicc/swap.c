#include <stdio.h>

int main(){
    int a, b, *p, *q, *t;
    scanf("%d %d", &a, &b);
    p=&a; q=&b;
    t=p;
    p=q;
    q=t;
    printf("%d %d", *p, *q);
}