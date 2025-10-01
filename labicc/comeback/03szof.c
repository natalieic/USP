/*
09 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Tamanho de um Vetor / sizeof 2 (Aula 3 - 28/03/2024)
    Descrição:
    Implemente um programa em C que leia na entrada padrão de texto um número inteiro n. Suponha que existam 3 vetores
    de tamanho n, um formado por chars, outro por ints e outro por doubles. O programa deve imprimir na tela o espaço ocupado
    (em bytes) por cada um dos vetores, seguidos por uma quebra de linha.
    • Utilize a função sizeof neste exercício.
    • ATENÇÃO! Os tamanhos dos vetores podem ser muito grandes. Por muito grande, entenda-se um valor na ordem de −2^63 até 2^63 − 1
*/

#include <stdio.h>

int main(void){
    long long n=0;

    scanf("%lld", &n);
    printf("Os vetores ocupam o seguinte espaço\n\nchar: %llu bytes\nint: %llu bytes\ndouble: %llu bytes\n", n*sizeof(char), n*sizeof(int), n*sizeof(double));
    
    return 0;
}

/*
    Usar sizeof para mdeir o tamanho de um conjunto de valores.
    Tamanho do vetor pode ser muito grande, importante considerar os tipos de dado maiores.
    1.in era vazio, 1.out era tudo zero. Antes de inicializar n=0, imprimia lixo.
*/