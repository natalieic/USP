#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *inv, temp[15], arq[9], *p;

    scanf("%s %8s", temp, arq);

    int len=strlen(temp);
    inv=(char*)malloc(len+1);
    strcpy(inv, temp);
    inv[len]='\0';

    FILE *fp = fopen(arq, "rb+");

    fseek(fp, 0, SEEK_END);
    int tam=ftell(fp);
    rewind(fp);

    p=(char*)malloc(tam+1);
    fread(p, sizeof(char), tam, fp);
    p[tam]='\0';

    char *q=strstr(p, inv);
    if(((*(q-1))==' ')&&((*(q+len))==' '))
        *(q-1)='\0';
    else
        *q='\0';

    strcat(p, q+len);

    freopen(arq, "wb", fp);
    fwrite(p, sizeof(char), strlen(p), fp);
    fclose(fp);

    printf("%s\n", p);

    free(p);
    free(inv);
    
    return 0;
}