#include <stdio.h>

int main(void){

    int l, m, n, *o, *p, **q;

    scanf("%d", &l);

    m=l;
    p=&m;
    *p+=10;
    n=m;
    o=&n;
    q=&o;
    **q+=10;

    printf("Valor inicial da variavel: %d\nValor do ponteiro antes do incremento: %d\nValor do ponteiro depois do incremento: %d\nValor do ponteiro para ponteiro antes do incremento: %d\nValor do ponteiro para ponteiro depois da mudanca: %d\nValor final da variavel: %d\n", l, l, *p, m, **q, **q);

    return 0;
}