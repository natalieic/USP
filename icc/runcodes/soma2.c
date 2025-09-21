#include <stdio.h>

int main (){
    int n, m, a[30], b[30], c=0;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%d", a+i);
        c<<=1;
        c+=*(a+i);
    }
    n=0;
    for(int i=0; i<m; i++){
        scanf("%d", b+i);
        n<<=1;
        n+=*(b+i);
    }
        printf("%d\n", c+n);
}