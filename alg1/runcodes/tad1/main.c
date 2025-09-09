#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main(void){
    PONTO *p, *centro;
    CIRCULO *r;
    float x_ponto, y_ponto, x_centro, y_centro, raio;

    scanf("%f %f %f %f %f", &x_ponto, &y_ponto, &x_centro, &y_centro, &raio);

    p=ponto_criar(x_ponto, y_ponto);
    centro=ponto_criar(x_centro, y_centro);

    r=circulo_criar(centro, raio);

    printf("Ponto: (%.1f, %.1f)\nCirculo: Centro (%.1f, %.1f), Raio = %.1f\n", ponto_get_x(p), ponto_get_y(p), ponto_get_x(centro), ponto_get_y(centro), (float)circulo_get_raio(r));

    ponto_apagar(&p);
    ponto_apagar(&centro);
    circulo_apagar(&r);

    return 0;
}