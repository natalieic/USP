#include <stdio.h>

int main (void){
    float m;
    int t=0;

    scanf("%f", &m);
    printf("massa inicial: %0.3f,", m);

    while (m>=0.5){
        m/=2;
        t+=50;
    }
    printf(" massa final: %0.3f %d hora(s), %d minuto(s) e %d segundo(s)", m, t/3600, (t%3600)/60, (t%3600)%60);
}