#include <stdio.h>

int main (){
    int n;
    float s=0, u=-1;
    scanf("%d", &n);

    for (int i=1; i<=n; i++){
        u*=-1;
        s+=u/i;
    }
    printf("%.4f\n", s);
}