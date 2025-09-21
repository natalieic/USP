#include <stdio.h>

int main(){
    FILE *fp1, *fp2; char c;

    fp1=fopen("f1.txt", "w");
    for(int i=0; i<7; i++){
        scanf("%c", &c);
        fputc("f1.txt", c);
    }

    fp2=fopen("f2.txt", "r");
    for(int i=0; i<7; i++){
        c=fgetc("f1.txt");
        fputc("f2.txt", c);
    }
    fclose(fp1);
    fclose(fp2);

}