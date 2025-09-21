#include <stdio.h>

int main (){
    short unsigned int a, b, c;
    long long int r=0;

    scanf ("%hu %hu %hu", &a, &b, &c);
    r = c;
    r <<= 16;
    r += b;
    r <<= 16;
    r +=a;
    printf ("%lld\n", r);


}