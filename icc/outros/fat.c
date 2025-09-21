#include <stdio.h>

int main (){
    long double n, fat;
    fat=1;
    scanf("%Lf", &n);
    for(short int i=0; i<n; i++){
        fat*=i+1;
    }
    printf("%.0Lf\n", fat);
}
//calcula até 25! só k