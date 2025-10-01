#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct l{
    char *titulo, *autor;
    short ano, qtd;
}Dados;

short cadastro(Dados *livro, short n, short m);

int main(void){
    short n, m, rep=0;
    Dados *livro;

    scanf("%hd", &n);

    if((livro=(Dados*)malloc(n*sizeof(Dados)))==NULL){
        printf("\nErro na alocação de memoria.\n");
        exit(1);
    }

    m=n;

    while(m>0){
        rep+=cadastro(livro, n, m+rep);
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
    getchar();

    for(short i=0; i<n-m; i++){
        if(strcmp(tit, livro[i].titulo)==0){
            livro[i].qtd++;
            t=1;
            scanf(" %*[^\n]");
            getchar();
            break;
        }
    }
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