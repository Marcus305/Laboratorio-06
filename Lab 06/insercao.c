#include "insercao.h"
#include <stdio.h>
//=============================================================================
void insercao(int *array, int n){
    for (int i = 1; i < n; i++) {
      int tmp = array[i];
      int j = i - 1;

      while ((j >= 0) && (array[j] > tmp)) {
         array[j + 1] = array[j];
         j--;
      }
      array[j+1] = tmp;
   }
}

void insercao2(uint64_t *array, uint64_t n){
    unsigned long long int comp=0, trocas=0;
    for (unsigned long long int i = 1; i < n; i++) {
      unsigned long long int tmp = array[i];
      unsigned long long int j = i - 1;
        //trocas++;
        //comp++;
      while ((j >= 0) && (array[j] > tmp)) {
         comp++;
         trocas++;
         array[j + 1] = array[j];
         if (j==0) {
            break;
         }
         j--;
      }
      trocas++;
      array[j+1] = tmp;
   }

   printf("Comparacoes: %llu - Trocas: %llu ", comp, trocas);
}
//=============================================================================
