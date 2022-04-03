#include "selecao.h"
#include "stdio.h"
//=============================================================================
void selecao(int *array, int n){
  uint64_t comparacao=0, troca=0;
    for (int i = 0; i < (n - 1); i++) {
      int menor = i;
      for (int j = (i + 1); j < n; j++){
        comparacao++;
         if (array[menor] > array[j]){
            menor = j;
           troca++;
         }
      }
      swap(&array[menor], &array[i]);
   }
  printf("Comp: %lu - Trocas: %lu - ", comparacao, troca);
}

void selecao2(uint64_t *array, uint64_t n){
  unsigned long long int comparacao=0, troca=0;
    for (unsigned long long int i = 0; i < (n - 1); i++) {

      unsigned long long int menor = i;
      for (unsigned long long int j = (i + 1); j < n; j++){
        comparacao++;
         if (array[menor] > array[j]){
            menor = j;

         }
      }

      swap2(&array[menor], &array[i]);
        troca+=3;
   }
  printf("%llu - %llu -", comparacao, troca);
}
//=============================================================================
