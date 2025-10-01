#include <stdio.h>

int main (){
    for(int i=1000; i<10000; i++){
        if((i/100+i%100)*(i/100+i%100)==i)
            printf("%d\n", i);
    }
}