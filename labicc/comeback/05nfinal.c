/*
10 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Nota de Cálculo (Aula 5 - 18/04/2024)
    Descrição:
    Seu programa irá receber a nota da P1 de cálculo, seguido da nota da p2, seguido das notas das 4 listas de exercício, a nota final será calculada como nfinal=(p1+p2+nlistas)/3 sendo nlistas a média das notas das listas.
    Se nfinal for Maior ou igual a 5, você foi aprovado.
    Se nfinal for menor do que 5 e maior ou igual a 3, você está de recuperação.
    Caso nfinal seja menos que 3, você foi reprovado.
    Além disso, caso a nota das listas seja zero, você será automaticamente reprovado.
*/
    
#include <stdio.h>

int main(void){
    float p1, p2, e1, e2, e3, e4, nfinal;

    scanf("%f %f %f %f %f %f", &p1, &p2, &e1, &e2, &e3, &e4);

    nfinal=(p1+p2+(e1+e2+e3+e4)/4)/3;

    if(e1+e2+e3+e4==0||nfinal<3)
        printf("Reprovado\n");
    else if(nfinal>=5)
        printf("Aprovado\n");
    else
        printf("Recuperacao\n");

    return 0;
}

/*
    Literalmente só if else ?
    Tinha feito:

    if(e1+e2+e3+e4==0||nfinal<3)
        printf("Reprovado\n");
    else if(nfinal>=3&&nfinal<5)
        printf("Recuperacao\n");
    else if(nfinal>=5)
        printf("Aprovado\n");
    mas que mico né
*/