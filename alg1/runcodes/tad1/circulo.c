#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "circulo.h"

struct circulo_{
    PONTO *centro;
    float raio;
};

CIRCULO *circulo_criar (PONTO *p, float raio){
    CIRCULO *c;

    c=(CIRCULO*)malloc(sizeof(CIRCULO));

    c->centro=p;
    c->raio=raio;

    return c;
}

bool circulo_set_ponto (CIRCULO *c, PONTO *p){
    if(c!=NULL){
        c->centro=p;
        return true;
    }

    return false;
}

bool circulo_set_raio (CIRCULO *c, int raio){
    if(c!=NULL){
            c->raio=raio;
            return true;
        }
        
        return false;
}

PONTO *circulo_get_ponto (CIRCULO *c){
    return c->centro;
}

int circulo_get_raio (CIRCULO *c){
    return c->raio;
}

void circulo_apagar (CIRCULO **circulo){
    free(*circulo);
    *circulo=NULL;
}