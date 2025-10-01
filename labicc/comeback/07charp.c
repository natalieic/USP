#include <stdio.h>

int main(void){
    char s[26]={'\0'};

    scanf("%[^\n]", s);

    for(int i=0; *(s+i)!='\0'; i++)
        printf("%c\n", *(s+i));

    return 0;
}