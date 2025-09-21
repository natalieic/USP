#include <stdio.h>
#include <stdlib.h>
#include <string.h>



    /*Defina um tipo de dado que contenha o nome, endereço e telefone de uma pessoa.
    Não utilize typedef. Crie uma variável do tipo de dado especificado.*/

/*
int main(){
    struct info{
        char nome[100];
        char endereco[200];
        char telefone[25];
    };
    struct info pessoa1;

    //scanf(" %[^\n]s", pessoa1.nome);
    fgets(pessoa1.nome, 100, stdin);

    printf("%s", pessoa1.nome);
}
*/
    

    /*Defina um tipo de dado que contenha o nome, endereço e telefone de uma pessoa.
    Utilize typedef. Crie uma variável do tipo de dado especificado.*/
/*
int main(){
    typedef struct{
        char nome[100];
        char endereco[200];
        char telefone[25];
    }info;

    info pessoa2;

    fgets(pessoa2.telefone, 25, stdin);

    printf("%s", pessoa2.telefone);
}
*/

    /*Crie um tipo de dado chamado “fracao” que conterá o numerador e o denominador de uma fração.
    No seu programa, peça que o usuário digite os valores (numerador e denomidador) de duas frações, 
    e em seguida, retorne a soma dessas duas frações, no formato a/b.*/
/*
typedef struct{
        int num, den;
}fracao;

fracao ler(fracao *x){
    printf("Numerador:");
    scanf("%d", &x->num);
    printf("Denominador:");
    scanf("%d", &x->den);
    return *x;
}

fracao soma(fracao f1, fracao f2){
    fracao fs={(f1.num*f2.den)+(f2.num*f1.den), f1.den*f2.den};
    return fs;
}

int main(){
    fracao a, b;
    ler(&a); ler(&b);
    fracao s=soma(a, b);
    printf("%d/%d", s.num, s.den);
}
*/

    /*Faça as declarações necessárias para criar um tipo de dado para armazenar as seguintes informações:
    os registros dos funcionários de uma empresa. A empresa possui 150 empregados.
    Cada registro possui as seguintes informações: número funcional, nome, PCD, idade e salário.*/
/*
typedef struct{
    int nfunc;
    char *nome;
    char pcd;
    int idade;
    float salario;
}registro;

int main(){
    registro funcionario[150];
}
*/

    /*Desenvolva um programa em C que aloque
dinamicamente um vetor de doubles com a
dimensão (tamanho) e os elementos
determinados pelo usuário.*/
/*
double* aloca(double *ponteiro, int tam){
    if((ponteiro=(double*)malloc(tam*sizeof(double)))==NULL){
        printf("Erro na alocação do vetor.\n");
        exit(1);
    }
}

int main(void){
    double *p; int tamanho;

    scanf("%d", &tamanho);

    p=aloca(p, tamanho);

    for(int i=0; i<tamanho; i++){
        scanf("%lf", &p[i]);
    }

    for(int i=0; i<tamanho; i++){
        printf("%lf ", p[i]);
    }
    return 0;
}
*/

