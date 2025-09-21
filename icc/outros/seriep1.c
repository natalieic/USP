#include <stdio.h>
int main (){
    double x, y, e, p, f;
    int i;
    e=0; p=1; f=1;
    scanf("%lf %lf", &x, &y);
    for(i=0; i>=0; i++){
        p*=x;
        f*=i+1;
        if (p/f<y) break;
        e+=p/f;
    }
    printf("O resultado é %lf e a serie tem %d termo(s).\n", e, i+1);
}