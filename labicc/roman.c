#include <stdio.h>

char inteiroParaRomano (int u, char *romano);

int main(){
    int n, inteiro[50], t; char romano[20]={'\0'};

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &inteiro[i]);
        *romano=inteiroParaRomano(inteiro[i], romano);
        t=0;
        while(romano[t]!='\0'){
            printf("%c", romano[t]);
            t++;
        }
        printf("\n");
    }
    return 0;

}

char inteiroParaRomano (int u, char *romano){
    int m, ct=0;
    if(u>=1000){
        m=u/1000;
        while(m>0){
            romano[ct]='M';
            ct++;
            m--;
            u-=1000;
        }
    if(u>=900)
    }
    return *romano;
}