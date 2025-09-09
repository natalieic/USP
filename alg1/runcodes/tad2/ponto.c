#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto_{
    float coord_x, coord_y;
};

PONTO* ponto_criar(float x, float y){
    PONTO *p;

    p=(PONTO*)malloc(sizeof(PONTO));

    p->coord_x=x;
    p->coord_y=y;

    return p;
}

void ponto_apagar(PONTO** p){
    free(*p);
    *p=NULL;
}

bool ponto_set(PONTO* p, float x, float y){
    if(p!=NULL){
        p->coord_x=x;
        p->coord_y=y;

        return true;
    }
    return false;
}

float ponto_get_x (PONTO *p){
    return p->coord_x;
}

float ponto_get_y (PONTO *p){
    return p->coord_y;
}

void ponto_print (PONTO *p){
    printf("(%.1f, %.1f)", p->coord_x, p->coord_y);
}

/*  A função distância foi implementada no TAD PONTO por ser uma operação entre pontos e não envolver o conceito de círculos. Como os arquivos do TAD CIRCULO incluem os de PONTO, a função fica acessível para os usuários de ambas bibliotecas.   */
float distancia(PONTO *pa, PONTO *pb){
    return sqrt(pow((pa->coord_x - pb->coord_x), 2)+ pow((pa->coord_y - pb->coord_y), 2));
}