#include <stdio.h>
#include "item.h"
#include "ABB.h"

int main(void) {
  int n;
  scanf("%d", &n);
  
  ABB* arvore = abb_criar();
  
  for(int i = 0; i < n; i++) {
    int chave;
    scanf("%d", &chave);

    abb_inserir(arvore, item_criar(chave, NULL));
  }

  if(abb_perfeitamente_balanceada(arvore)) {
    printf("É PERFEITAMENTE BALANCEADA SIM!\n");
  }
  else {
    printf("NÃO!\n");
  }

  abb_apagar(&arvore);

  return 0;
}
