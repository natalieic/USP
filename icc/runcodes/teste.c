#include <stdio.h>

int main(){
    int n, x=0; char c;
    //scanf("%d", &n);
        //for(int i=0; i<n; i++){
        scanf("%c", &c);
        x^=1<<(c-97);
        printf("%d", x);
    
}