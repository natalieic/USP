/*
05 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Catálogo Biblioteca (Aula 12 - 06/06/2024)
    Descrição:
    Imagine que você está trabalhando em um projeto para uma biblioteca comunitária que deseja criar
    um sistema simples para gerenciar seus livros. A biblioteca tem um orçaamento limitado e decidiu usar
    a linguagem C para desenvolver uma aplicação leve e eficiente. Sua tarefa é criar um programa que
    gerencie dinamicamente um catálogo de livros, permitindo que novos livros sejam adicionados, exibidos
    e a memória seja gerenciada corretamente.
    Para isso, seu programa irá receber o número (N) de livros a serem cadastrados e, nas próximas N
    linhas, receberá o título, o autor e o ano de publicação de cada livro (separados por vírgulas) presente
    na biblioteca. Assim, você deve armazená-los em vetores alocados dinamicamente e depois imprimí-los
    em formato de catálogo, como mostrado no caso teste abaixo (Mostrando o título, o nome do autor,
    o ano de publicação e a quantidade desse livro).
    Instruções Complementares:
    • ATENÇÃO: Utilize a biblioteca stdlib.h para importar funções como: calloc(), malloc(),
    realloc() e free().
    • Não use vetores estáticos, utilize APENAS vetores dinâmicos.
    • 0 ≤ N ≤ 100, 0 < titulo < 100, 0 < nomeAutor < 50. Porém, deve-se ocupar somente a
    memória estritamente necessária.
    • Permitida a utilização da biblioteca string.h.
    • Não esqueça de DESALOCAR a memória ao final do programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct l{
    char *titulo, *autor;
    short ano, qtd;    /* não sei por que não funciona qtd=0 */
}Dados;

short cadastro(Dados *livro, short n, short m);

int main(void){
    short n, m, rep=0;
    Dados *livro;    /* ponteiro para vetor de structs do tipo Dados */

    scanf("%hd", &n);

    if((livro=(Dados*)malloc(n*sizeof(Dados)))==NULL){    /* aloco o vetor de livros */
        printf("\nErro na alocação de memoria.\n");
        exit(1);
    }

    m=n;

    while(m>0){
        rep+=cadastro(livro, n, m+rep);    /* cadastro um a um */
        m--;
    }

    printf("Catalogo de Livros:");

    for(short i=0; i<n-rep; i++){
        printf("\nLivro %hd:\nTitulo: %s\nAutor: %s\nAno: %hd\nQuantidade: %hd", i+1, livro[i].titulo, livro[i].autor, livro[i].ano, livro[i].qtd);
        if(i<n-rep-1)
            printf("\n");

        free(livro[i].titulo);
        livro[i].titulo=NULL;
        free(livro[i].autor);
        livro[i].autor=NULL;
    }
    
    free(livro);
    livro=NULL;

    return 0;
}

short cadastro(Dados *livro, short n, short m){
    char tit[100], aut[50], t=0;

    scanf(" %[^,],", tit);
    getchar();    /* consumir a vírgula */

    for(short i=0; i<n-m; i++){
        if(strcmp(tit, livro[i].titulo)==0){
            livro[i].qtd++;
            t=1;
            scanf(" %*[^\n]");
            getchar();    /* consumir a quebra de linha */
            break;
        }
    }
    /* o laço acima compara o título recém coletado com os outros títulos já cadastrados. Caso a comparação indique
    compatibilidade, a quantidade daquele exemplar é incrementada no registro e o resto dos dados é
    ignorado para garantir a funcinalidade e eficiência do programa. */

    if(!t){
        scanf(" %[^,], %hd", aut, &(livro[n-m].ano));
        getchar();
        
        short int len=strlen(tit);
        livro[n-m].titulo=(char*)malloc(len+1);
        strcpy(livro[n-m].titulo, tit);
        (livro[n-m].titulo)[len]='\0';

        len=strlen(aut);
        livro[n-m].autor=(char*)malloc(len+1);
        strcpy(livro[n-m].autor, aut);
        (livro[n-m].autor)[len]='\0';

        livro[n-m].qtd=1;
    }
    
    return t;
}