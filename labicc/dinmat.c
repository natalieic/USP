#include <stdio.h>
#include <stdlib.h>

int* fill(int n, int *p);
void print(int n, int *p);

int main(){
    int n, *p;

    scanf("%d", &n);
    p=(int*)malloc(n*sizeof(int));
    fill(n, p);
    print(n, p);
    free(p);
}

int* fill(int n, int *p){
    for(int i=0; i<n; i++)
        scanf("%d", p+i);
    return p;
}

void print(int n, int *p){
    int i=0;
        while(i<n){
            for(int j=0; j*j<n; j++){
                printf("%d ", p[i]);
                i++;
            }
            printf("\n");
        }
}