#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minusculo(char *s, int tam);

int main (void){
    char arq[6], temp[10], *palavra, *p;

    scanf("%5s %s", arq, temp);

    int len=strlen(temp);
    palavra=(char*)malloc(len+1);
    strcpy(palavra, temp);
    palavra[len]='\0';

    FILE *fp=fopen(arq, "r");

    fseek(fp, 0, SEEK_END);
    int tam=ftell(fp);
    p=(char*)malloc(tam+1);
    rewind(fp);
    fread(p, sizeof(char), tam, fp);
    fclose(fp);
    p[tam]='\0';

    maiusculo(palavra, len);
    maiusculo(p, tam);

    int ct=0;
    char ant, dps;

    for(int i=0; i<tam+1; i++){
        if(!strncmp(p+i, palavra, len)){
            
            ant=(!i||(*(p+i-1)<'a')||(*(p+i-1)>'z'));
            dps=((i+len==tam)||(*(p+i+len)>'z')||(*(p+i+len)<'a'));

            if(ant&&dps){
                ct++;
                i+=len-1;
            }
        }
    }

    printf("quantidade: %d\n", ct);

    free(p);
    free(palavra);
}

void maiusculo(char *s, int tam){
    for(int i=0; i<tam; i++){
        if(s[i]>='A'&&s[i]<='Z')
            s[i]+=32;
    }
}