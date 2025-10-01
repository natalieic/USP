#include <stdio.h>

int main (){
    int n, m, a[10], b[10], ct, c=0; char in[10]={'\0'};

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<n; i++){
        //printf("a[%d] é %d\n", i, a[i]);
        for(int j=0; j<m; j++){
            //printf("b[%d] é %d\n", j, b[j]);
            if(a[i]==b[j]){
                in[c] = a[i];
                c++;
            }
        }

    }

    for(int i=0; i<10; i++){
        if(in[i]=='\0')
            ct++;
        else 
            printf("%d ", in[i]);
    }
    if(ct==10)
        printf("vazio\n")
}
/*TENTATIVA DE USAR BITMASK*/
#include <stdio.h>

int main(){
    int m, n, a, b;
    unsigned long long int x=0, y=0;

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &a);
        x|=1<<a;
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &b);
        y|=1<<b;
    }
    intersecao x&y
    a-b x&!y
}