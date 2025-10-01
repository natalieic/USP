#include <stdio.h>

int main(){
    int x, *p, **q;
    scanf("%d", &x);
    p=&x;
    *p+=10;
    q=&p;
    **q+=10;
    printf("Valor inicial da variavel: %d\nValor do ponteiro antes do incremento: %d\nValor do ponteiro depois do incremento: %d\nValor do ponteiro para ponteiro antes do incremento: %d\nValor do ponteiro para ponteiro depois da mudanca: %d\nValor final da variavel: %d\n",
    **q-20, **q-20, **q-10, **q-10, **q, **q);
}