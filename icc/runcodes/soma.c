#include <stdio.h>
int main (){
    int n, m, a, c=0, d=0;
    scanf ("%d %d", &n, &m);

    for (int i=0; i<n; i++){
        c<<=1;
        scanf ("%d", &a);
        c += a;
    }
    for (int i=0; i<m; i++){
        d<<=1;
        scanf ("%d", &a);
        d += a;
    }
    printf("%d", c+d);
}