#include <stdio.h>

int main (){
    int n, m, a[10], b[10];

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    /*scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
    }*/

    printf("intersecao: %d", *a);
    /*for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }*/
    
}