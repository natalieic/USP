#include <stdio.h>
#include <stdlib.h>

int main (void){

    long long int n, acm=1;
    scanf("%lld", &n);
    while (n>0) {
        acm *= n;
        n--;
    }
    printf("%lld\n", acm);

}