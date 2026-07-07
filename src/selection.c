#include "sorts.h"

void selectionSort(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        int menor = i;
        for (int j = i + 1; j < tamanho; j++){
            if (vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if (menor != i){
            int aux      = vetor[i];
            vetor[i]     = vetor[menor];
            vetor[menor] = aux;
        }
    }
}