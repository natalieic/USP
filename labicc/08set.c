#include <stdio.h>

int main(void){
    int a[10], b[10], in[10], ta, tb, tin;

    scanf("%d", &ta);

    for(int i=0; i<ta; i++)
        scanf("%d", &a[i]);

    scanf("%d", &tb);

    for(int i=0; i<tb; i++)
        scanf("%d", &b[i]);

/*INTERSECÇÃO*/
    tin=0;
    for(int i=0; i<ta; i++){
        for(int j=0; j<tb; j++){
            if(a[i]==b[j]){
                in[tin]=a[i];
                tin++;
            }
        }
    }

    for(int i=0; i<tin-1; i++){
        for(int j=0; j<tin-1-i; j++){
            if(in[j]in[j]){

            }
        }
    }

    for(int i=0; i<tin-1; i++){
        if(in[i]==in[i+1]){
            for(int j=i; j<tin-1; j++)
                in[j]=in[j+1];
            tin--;
        }
    }

    printf("intersecao: ");
    for(int i=0; i<tin; i++)
        printf("%d ", in[i]);
    printf("\n");

    return 0;
}