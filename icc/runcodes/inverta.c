#include <stdio.h>

int main(){
    int n, v[100000];

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", v+i);

    while(n>0){
        printf("%d ", *(v+n-1));
        n--;
    }
    printf("\n");
}