#include <stdio.h>

int main () {
    int dia, b;

    scanf("%d %d", &dia, &b);
    if (dia>0 && dia<8){
        switch (dia) {
            case 1: printf ("Segunda: Aula de computacao\n");
                if (b==1)
                    break;
            case 2: printf ("Terca: Treino de volei\n");
                if (b==1)
                    break;
            case 3: printf ("Quarta: Aula de calculo\n");
                if (b==1)
                    break;
            case 4: printf ("Quinta: Lista de GA\n");
                if (b==1)
                    break;
            case 5: printf ("Sexta: Festa da Sacim\n");
                if (b==1)
                    break;
            case 6: printf ("Sabado: Jantar em familia\n");
                if (b==1)
                    break;
            case 7: printf ("Domingo: Depressao pos final de semana\n");
                if (b==1)
                    break;
        }
    } else
        printf("Dia nao registrado\n");
}