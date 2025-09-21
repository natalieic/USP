#include <stdio.h>

int main (){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    while(b<a||c<a||c<b){
        if(b<a){
            b-=a;
            a+=b;
            b=a-b;
        }
        if(c<b){
            c-=b;
            b+=c;
            c=b-c;
        }
        if(c<a){
            c-=a;
            a+=c;
            c=a-c;
        }
    }
    printf("%d %d %d\n", a, b, c);
}
    