#include <stdio.h>

int main (){
    int a, b, n;
    a=1; b=1;
    scanf("%d", &n);
    while (n>1){
        b+=a;
        a=b-a;
        n--;
    }
    printf("%d\n", b);
}