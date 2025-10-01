#include <stdio.h>

int main(){
    int n=6, a[6], temp, w=n;
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    while(w>0){
        for(int i=0; i<n; i++){
            if(i!=0 && a[i]>a[i-1]){
                temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
            }
        }
        w--;
    }
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}