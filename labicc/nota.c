#include <stdio.h>

int main (void){
    float p1, p2, l1, l2, l3, l4, nfinal;

    scanf ("%f %f %f %f %f %f", &p1, &p2, &l1, &l2, &l3, &l4);
    nfinal=(p1+p2+(l1+l2+l3+l4)/4)/3;

    if (nfinal<3 || l1==l2 && l2==l3 && l3==l4 && l1==0)
        printf ("Reprovado\n");
    else if (nfinal>=5)
        printf ("Aprovado\n");
    else 
        printf ("Recuperacao\n");    
}