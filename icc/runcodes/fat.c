#include <stdio.h>

int main (){
    long int n;
    int z=0;
    scanf ("%ld", &n);
    while (n>=5){
        z+=n/5;
        n/=5;
    }
    printf("%d\n", z);
}