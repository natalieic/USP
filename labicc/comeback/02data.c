/*
08 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Formatador de Data (Aula 2 - 28/03/2024)
    Descrição:
    Implemente um programa em C que leia na entrada padrão de texto uma data desformatada composta de dia,
    mês e ano. Imprima na tela a data formatada da seguinte maneira: **/**/****, seguida por uma quebra de linha.
*/

#include <stdio.h>

int main(void){
    int data;
    scanf("%d", &data);
    printf("%02d/%02d/%04d\n", data/1000000, (data%1000000)/10000, (data%1000000)%10000);

    return 0;
}

/*
    Sabia que dava pra imprimir com zero na frente mas só agora descobri como faz.
    O raciocínio das divisões inteiras e dos restos eu lembrei da aula do Manzato mesmo.
    Achei que esse jeito fosse melhor do que criar variáveis.
*/