#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char string[100], temp[10], *palavra, *p;

    scanf("%[^\n] %s", string, temp);

    int len=strlen(temp);
    palavra=(char*)malloc(len+1);
    strcpy(palavra, temp);
    palavra[len]='\0';

    int tam=strlen(string);
    p=(char*)malloc(tam+1);
    strcpy(p, string);
    p[tam]='\0';

    int ct=0;

    char ant, dps;

    for(int i=0; i<=tam-len; i++){
        if(strncmp((p+i), palavra, len)==0){
            ant=(!i||(*(p+i-1)<'a')||(*(p+i-1)>'z'));
            dps=((i+len==tam)||(*(p+i+len)>'z')||(*(p+i+len)<'a'));
            if(ant&&dps){
                ct++;
                i+=len-1;
            }
        }
    }
    printf("%d", ct);
    free(palavra);
    free(p);

}
