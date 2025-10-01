/*
10 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Quadrado ou Retângulo? (Aula 5 - 18/04/2024)
    Descrição:
    Implemente um programa em C que leia na entrada padrão de texto quatro inteiros a b c d, que representeam lados consecutivos de um quadrilátero. Assumindo que todos os ângulos são retos, a saída deve determinar se o quadrilátero é um quadrado ou só um retângulo qualquer, seguido por uma quebra de linha.
*/

#include <stdio.h>

int main(void){
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);
        
    if(a&&a==b&&a==c&&a==d)
        printf("quadrado!\n");
    else if(a&&b&&a==c&&b==d)
        printf("retangulo!\n");
    else
        printf("nenhum!\n");

    return 0;
}

/*
Ordem dos ifs

faria também 

    if(!(a&&b&&c&&d))
        printf("nenhum!\n");
    else if(a==b&&a==c&&a==d)
        printf("quadrado!\n");
    else if(a==c&&b==d)
        printf("retangulo!\n");
    else
        printf("nenhum!\n");

*/