#include <stdio.h>

int main (void) {

	char primo[101];
    int n = 100;

    for (int i = 0; i < n+1; i++){
        primo[i] = 1;
    }
	primo[0]=0;
	primo[1]=0;

	for (int i = 2; i*i <= n; i++) {
		if (primo[i]) {
            for (int j = i*i; j <= n; j += i) {
                primo[j] = 0;
            }
        }
	}
    for (int i=0; i<n+1; i++){
        if(primo[i])
            printf("%d ", i);
    }
}