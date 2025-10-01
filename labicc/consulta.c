#include <stdio.h>
#include <stdlib.h>

int codigo(int c);
short int* divisor(int c);
char* ler(int tam);

int main(){
    short int n, ip, *vip/*sort em ip decrescente*/, *cod;
    char **str;

    scanf("%hd", &n);
    if(!n){
        printf("Sem produtos a serem cadastrados\n");
        return 0;
    }
    vip=(short int*)malloc(n*sizeof(short int));
    cod=(short int*)malloc(n*sizeof(short int));
    str=(char**)malloc(n*sizeof(char*));

    short int w=n;
    while(w>0){ 
        scanf("%hd", &ip);
        vip[ip]=ip;
        scanf("%hd", &cod[ip]);
        short int tam=codigo(cod[ip]);
        str[ip]=ler(tam);
        w--;
    }
    for(int i=n-1; i>=0; i--){
        printf("%s %hd\n", str[i], cod[i]);
    }
    for(int i=0; i<n; i++)
        free(str[i]);
    free(vip); free(cod); free(str);

}

int codigo(int c){
    char ct;
    short int *div=divisor(c), p=0;
        for(int i=1; i<=div[0]; i++){
            ct=0;
            for(int j=2; j*j<=div[i]; j++){
                if(div[i]%j==0){
                    ct++; break;
                }
            }
            if(ct)
                continue;
            p+=div[i];
        }
    free(div);
    return p;
}

short int* divisor(int c){
    short int d=1, *div;
    for(int i=2; i<=c/2; i++){
        if(c%i==0)
            d++;
    }
    div=(short int*)malloc((d+1)*sizeof(short int));//vetor div pra guardar os divisores
    int k=1;
    for(int i=2; i<=c/2; i++){
        if(c%i==0){
            div[k]=i; k++;
        }
    }
    div[d]=c;
    div[0]=d;
    return div;
}

char* ler(int tam){
    char *s=(char*)malloc((tam+1)*sizeof(char));
    for(int i=0; i<tam; i++)
        scanf(" %c", &s[i]);
    return s;
}