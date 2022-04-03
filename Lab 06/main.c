#include "bolha.h"
#include "countingsort.h"
#include "heapsort.h"
#include "insercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "selecao.h"
#include "shellsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <winbase.h>
#include <psapi.h>
//=============================================================================


double get_memory_used_MB()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess( ), &info, sizeof(info) );
    return (double)info.PeakWorkingSetSize/ (1024*1024);
}


void teste(uint64_t n, char ordem){

   //Delcaracao de variaveis
    //int n = (argc < 2) ? 10000 : atoi(argv[1]);
    uint64_t*  array = (uint64_t*) malloc(n*sizeof(uint64_t));

    if(array == NULL){
      printf("NAO TEM MEMORIA\n");
      exit(0);
    }else{
      //printf("TEM MEMORIA\n");
    }

    // VARIAVEIS PARA CALCULAR O TEMPO
    clock_t inicio, fim;
    double total;
    size_t peakSize;
    double memory_used;





    //Geracao do conjunto a ser ordenado
    switch(ordem){
      case 'C': crescente2(array, n);
      break;
      case 'D': decrescente2(array, n);
      break;
      case 'A':  aleatorio2(array, n);
      break;
      default: aleatorio2(array, n);
    }

    //Mostrar o conjunto a ser ordenado
	 //mostrar(array, n);


    //Execucao do algoritmo de ordenacao
	 inicio = clock();
    //bolha2(array, n);
    //countingsort(array, n);
    //heapsort(array, n);
    insercao2(array, n);
    //mergesort(array, n);
    //quicksort(array, n);
    //selecao2(array, n);
    //shellsort(array, n);
	 fim = clock();
    total = ((fim - inicio) / (double)CLOCKS_PER_SEC);
    memory_used = get_memory_used_MB();


    //Mostrar o conjunto ordenado, tempo de execucao e status da ordenacao
	 //algoritmo.mostrar(array, n);
	 //printf(" - %f  -  %c - %lu\n", total, ordem, n);
	 printf("Tempo: %f s  - Tamanho do vetor: %lu - Memoria utilizada: %0.2f  MB\n", total, n, memory_used);
	 //printf("isOrdenado: %s\n", isOrdenado(array, n) ? "true" : "false");

    //Desalocar o espaco de memoria do array
    free(array);

}







//=============================================================================




int main(int argc, char **argv) {

  //int v[] = {33, 10, 75, 18, 29, 42};

  //bolha(v, 6);

   /* for(uint64_t i=10000000; i<=10000000; i=i*2){

       teste(i, 'C');
     //  teste(i, 'D');
      // teste(i, 'A');
    }*/

  for(uint64_t i=1000; i<=1024000; i=i*2){

      teste(i, 'C');
      //teste(i, 'D');
      //teste(i, 'A');
    }

 for(uint64_t i=1000; i<=1024000; i=i*2){

      //teste(i, 'C');
      teste(i, 'D');
      //teste(i, 'A');
    }

  for(uint64_t i=1000; i<=1024000; i=i*2){

      //teste(i, 'C');
      //teste(i, 'D');
      teste(i, 'A');

    }



    return 0;
}
