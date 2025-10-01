/*
09 de julho de 2024 - Natalie
Disciplina SCC0222 – Laboratório de Introdução à Ciência da Computação I
Exercício: Verificador de Troco (Aula 4 - 11/04/2024)
    Descrição:
    Seu programa irá receber uma entrada de um valor inteiro em reais e determinar a quantidade mínima de notas e moedas necessárias para representar esse valor.
*/

/*    Pensei em três maneiras de implementar esse e perguntei pro chatgpt    */


// PRIMEIRA:

/*
#include <stdio.h>

int main(void){
    int dindin;

    scanf("%d", &dindin);

    printf("%d nota(s) de R$ 200\n%d nota(s) de R$ 100\n%d nota(s) de R$ 50\n%d nota(s) de R$ 20\n%d nota(s) de R$ 10\n%d nota(s) de R$ 5\n%d nota(s) de R$ 2\n%d moeda(s) de R$ 1", dindin/200, (dindin%200)/100, ((dindin%200)%100)/50, (((dindin%200)%100)%50)/20, ((((dindin%200)%100)%50)%20)/10, (((((dindin%200)%100)%50)%20)%10)/5, ((((((dindin%200)%100)%50)%20)%10)%5)/2, ((((((dindin%200)%100)%50)%20)%10)%5)%2);

    return 0;
}
*/
/*
Segundo o gpt:
    The code performs the necessary calculations in a single line, which is efficient in terms of execution time.
    However, the repeated use of modulo and division operations might be slightly less efficient than storing intermediate results.
*/


// SEGUNDA:

#include <stdio.h>

int main(void){
    int dindin, nota[7]={200, 100, 50, 20, 10, 5, 2}, i=0;

    scanf("%d", &dindin);

    while(i<7){
        printf("%d nota(s) de R$ %d\n", dindin/nota[i], nota[i]);
        dindin%=nota[i];
        i++;
    }
    printf("%d moeda(s) de R$ 1\n", dindin);

    return 0;
}

/*
Tinha inicializado o vetor com
    nota[0]=200;
    nota[1]=100;
    nota[2]=50;
    nota[3]=20;
    nota[4]=10;
    nota[5]=5;
    nota[6]=2;
mas o gpt me avisou da vergonha que eu tava passando.
*/


// TERCEIRA:

/*
int main(void){
    int dindin, nota[7], i;

    for(i=0; i<7; i++){
        switch(i){
            case 0: nota[i]=200; break;
            case 1: nota[i]=100; break;
            case 2: nota[i]=50; break;
            case 3: nota[i]=20; break;
            case 4: nota[i]=10; break;
            case 5: nota[i]=5; break;
            case 6: nota[i]=2; break;
        }
    }
    i=0;

    scanf("%d", &dindin);

    while(i<7){
        printf("%d nota(s) de R$ %d\n", dindin/nota[i], nota[i]);
        dindin%=nota[i];
        i++;
    }
    printf("%d moeda(s) de R$ 1\n", dindin);

    return 0;
}
*/
/*
Quis inventar e fui moleque. Segundo o gpt:
    The code is efficient in terms of execution time, but the switch statement adds unnecessary overhead during initialization.
    Remove the switch statement to improve readability and maintainability.
*/