#include <stdio.h>

int main(){
    int n, qa, qv, i;
    float pc, pv, c=0, r=0, l=0;

    scanf("%d", &n);
    for(int j=1; j<=n; j++){
        scanf("%f %f %d %d", &pc, &pv, &qa, &qv);
        c+=pc*qa; r+=pv*qv;
        if(pv*qv-pc*qa>l){
            l=pv*qv-pc*qa;
            i=j;
        }
    }
    if(n==0){
        printf("Sem atividades registradas hoje\n");
        return 0;
    }
    if(r-c>=0)
        printf("lucro: %.2f\n", r-c);
    else
        printf("prejuizo: %.2f\n", (r-c)*-1);
    printf("produto: %d lucro relativo: %.2f\n", i, l);
}