#include <stdio.h>

int main(){
    char s[26]={0};
    scanf("%[^\n]%*c", s);

    for(int i=0; i<26; i++){
        if(*(s+i)!=0)
            printf("%c\n", *(s+i));
    }
}