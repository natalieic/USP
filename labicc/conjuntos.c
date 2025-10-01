#include <stdio.h>

int rep(int x, int v[], int tamanho);

int main(){
    int m, n, a[10], b[10], in[10], tamin=0, dif[10], tamdif=0;

    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<m; i++){
        if(rep(a[i], b, n) && !rep(a[i], in, tamin)){
            in[tamin++]=a[i];
        }
    }
    printf("intersecao: ");
    if(tamin==0){
        printf("vazio\n");
    }else{
        for(int i=0; i<tamin; i++){
            printf("%d ", in[i]);
        }
        printf("\n");
    }
    for(int i=0; i<m; i++){
        if (!rep(a[i], b, n)){
            dif[tamdif++]=a[i];
        }
    }
    printf("a - b: ");
    if(tamdif==0){
        printf("vazio\n");
    } else{
        for (int i=0; i<tamdif; i++){
            printf("%d ", dif[i]);
        }
        printf("\n");
    }
}
int rep(int x, int v[], int tamanho){
    for(int i=0; i<tamanho; i++){
        if(v[i]==x){
            return 1;
        }
    }
    return 0;
}