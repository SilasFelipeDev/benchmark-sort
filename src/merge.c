#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

static void merge(int *vetor, int inicio, int meio, int fim, Benchmark *bench){
    int i, j, k, n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = malloc(n1 * sizeof(int));
    int *direita  = malloc(n2 * sizeof(int));

    if (esquerda == NULL || direita == NULL){
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
        esquerda[i] = vetor[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j]  = vetor[meio + 1 + j];
    
    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2){
        bench->comparacoes++;
        if (esquerda[i] <= direita[j]){
            vetor[k++] = esquerda[i++];
            bench->trocas++;
        }
        else{
            vetor[k++] = direita[j++];
            bench->trocas++;
        }
    }

    while (i < n1){
        vetor[k++] = esquerda[i++];
        bench->trocas++;
    }
    while (j < n2){
        vetor[k++] = direita[j++];
        bench->trocas++;
    }
    
    free(esquerda);
    free(direita);
}

void mergeSort(int *vetor, int inicio, int fim, Benchmark *bench){
    if (inicio < fim){
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(vetor, inicio, meio, bench);
        mergeSort(vetor, meio + 1, fim, bench);
        merge(vetor, inicio, meio, fim, bench);
    }
}