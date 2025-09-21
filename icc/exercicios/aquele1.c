#include <stdio.h>
#include <math.h>

int main (){
    float x, s, temp, fat;
    int i=1;
    fat=1; s=0;
    scanf("%f", &x);
    while (i<=20){
        if (i==1){
            fat*=2*i-1;
            temp=x;
        }else{
            fat *= (2*i-1)*(2*i-2);
            temp = pow(x,2*i-2)/fat;
            if (i%2==0)
                temp *= (-1);}
        s+=temp;
        i++;}
        printf("%f\n", s);
}