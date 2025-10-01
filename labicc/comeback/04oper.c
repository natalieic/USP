/*
09 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Operadores Lógicos (Aula 4 - 11/04/2024)
    Descrição:
    Implemente um programa em C que leia na entrada padrão de texto dois números inteiros, seu programa deverá realizar
    os seguintes testes:
    1) Se n1 é maior que n2 E n1 menos n2 é divisível por 3.
    2) Se n2 é maior que n1 E n1 + n2 é maior que 400.
    3) Se n1 é igual a n2 E n1 é ímpar.
    Se qualquer um desses testes for verdadeiro, imprima n1 + n2, se não, seu programa deve imprimir
    ”Nenhuma condicao foi satisfeita” seguidos por uma quebra de linha.
    • Utilize o operador lógico || para separar os testes.
*/

#include <stdio.h>

int main(void){
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    if(((n1>n2)&&((n1-n2)%3==0))||((n2>n1)&&(n1+n2>400))||((n1==n2)&&((n1+1)%2==0)))
        printf("%d\n", n1+n2);
    else
        printf("Nenhuma condicao foi satisfeita\n");

    return 0;
}

/*
    Fui fazer sem ler o pdf inteiro e fiz errado (não li que era pra usar o ||).
    Na dúvida coloca parênteses. Fica ilegível mas você não vai ter que corrigir então não vai ter que ler depois.
*/

/*
int main(void){
    int n1, n2, var=0;

    scanf("%d %d", &n1, &n2);

    if(n1>n2&&((n1-n2)%3==0))
        var=1;
    else if(n2>n1&&(n1+n2)>400)
        var=1;
    else if(n1==n2&&(n2+1)%2==0)
        var=1;
    
    if(var)
        printf("%d\n", n1+n2);
    else
        printf("Nenhuma condicao foi satisfeita\n");
}
*/