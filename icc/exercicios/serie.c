#include <stdio.h>

int main (){
    double x, s, p, f;
    scanf("%lf", &x);
    s=x; p=1; f=1;

   for (int i=1; i<40; i+=2){
        p*=x*x*(-1);
        f*=(i+2)*(i+1);
        s += (p/f);
    }
    printf("%.4lf\n", s);
}