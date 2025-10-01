/*
10 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Área de Polígono Regular (Aula 4 - 11/04/2024)
    Descrição:
    Implemente um programa em C que leia na entrada padrão de texto um inteiro n e um double l.
    O programa deve imprimir na tela a área de um polígono regular com n lados de tamanho l, seguidos por uma quebra de linha.
    • Utilize a biblioteca math.h neste exercício.
    • defina π = 3.14159265358979323846
*/

#include <stdio.h>
#include <math.h>

int main(void){
    const double pi=3.14159265358979323846;
    int n;
    double l;

    scanf("%d %lf", &n, &l);

    printf("%lf\n", ((n*l)/2)*(l/(2*tan(pi/n))));

    return 0;
}

/*
Área do poligono é o semiperímetro vezes o apótema.
Semiperímetro é (n*l)/2
Apótema é l/(2*tan(pi/n)) -> segundo wikipedia

Definição de constante foi inédito e nuca mais apareceu nos exercícios de runcodes.
Aprender a compilar para usar a math.h (tinha que digitar manualmente gcc 04polig.c -o polig.c -lm), não sei se tem que por o std=c99 e sei lá o que.
%lf tem 6 casas depois do ponto.
*/