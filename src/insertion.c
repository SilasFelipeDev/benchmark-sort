#include "sorts.h"

void insertionSort(int *vetor, int tamanho, Benchmark *bench){
    for (int i = 1; i < tamanho; i++){
        int j   = i;
        int aux = vetor[j];
        while (j > 0){
            bench->comparacoes++;
            if (aux >= vetor[j - 1]) break;
            bench->trocas++;
            vetor[j] = vetor[j - 1];
            j--;
        }
        vetor[j] = aux;
    }
}