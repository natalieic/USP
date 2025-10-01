#include <stdio.h>
#include <stdlib.h>

int* ler(int tam);
void sort(int *p, int tam);
void print(int *p, int tam);
uniao();
ctintersec();

int main(){
    int m, n, *a, *b, *u;

    scanf("%d", &m); a=ler(m);
    scanf("%d", &n); b=ler(n);
    //sort(a, m); sort(b, n);
    print(a, m); print(b, n);
}

int* ler(int tam){
    int *p=(int*)malloc(tam*sizeof(int));
    for(int i=0; i<tam; i++)
        scanf("%d", &p[i]);
    return p;
}

void sort(int *p, int tam){
    int temp;
    for(int i=0; i<tam-1; i++){
        for(int j=0; j<tam-i-1; j++){
            if(p[j]>p[j+1]){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void print(int *p, int tam){
    for(int i=0; i<tam; i++)
        printf("%d ", p[i]);
}

int* uniao(int *a, int *b, int ta, int tb){
    int i, *v=(int*)malloc((ta+tb)*sizeof(int)), d=0;
    for(i=0; i<ta; i++)
        v[i]=a[i];
    for(int j=0; j<tb; j++){
        v[i]=b[j]; i++;
    }
    sort(v, ta+tb);
    for(int i=0; i<ta+tb-1; i++){
        if(v[i]==v[i+1]){
            d++; continue;
        } //quantos repetidos tem
    }
    int *p=(int*)malloc((ta+tb-d)*sizeof(int));
    int j=0;
    for(int i=0; i<ta+tb-1; i++){
        if(v[i]==v[i+1]){
            continue;
        }
        p[j]=v[i]; j++
    }
    print(p, )
    
    
    free(v);
}

int ctintersec(int ta, int tb){
    int ct=0;
    for(int i=0; i<ta; i++){
        for(int j=0; j<tb; j++){
            if(a[i]==b[j])
                ct++;
        }
    }
}

for(int i=0; i<m+n-ct; i++){
    if()
}