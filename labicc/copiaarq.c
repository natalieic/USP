#include <stdio.h>
#include <stdlib.h>

int main (void){
    char nome[13], *p;
    FILE *fp;
    int pos;

    scanf("%12s", nome);
    fp=fopen(nome, "rb");

    fseek(fp, 0, SEEK_END);
    pos=ftell(fp);
    rewind(fp);
    p=(char*)malloc(pos);

    fread(p, sizeof(char), pos, fp);
    fclose(fp);

    printf("%s\n", p);

    free(p);
}