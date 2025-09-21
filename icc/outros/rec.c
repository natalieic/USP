#include <stdio.h>

int antecess(int n){
    if(n<3)
        return n-1;
    printf("%d ", antecess(n-1));
}

int main(void){
    int n;

    scanf("%d", &n);

    printf("%d\n", antecess(n));

    return 0;
}