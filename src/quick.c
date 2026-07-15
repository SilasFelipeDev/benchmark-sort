#include "sorts.h"

static int particiona(int *vetor, int inicio, int fim, Benchmark *bench){
    int i = inicio;
    int j = fim;
    int pivo = vetor[inicio + (fim - inicio) / 2];

    while (i <= j){
        while (1){
            bench->comparacoes++;
            if (!(vetor[i] < pivo))
                break;
            i++;
        }
        while (1){
            bench->comparacoes++;
            if (!(vetor[j] > pivo))
                break;
            j--;
        }
        if (i <= j){
            bench->trocas++;
            int aux  = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(int *vetor, int inicio, int fim, Benchmark *bench){
    if (inicio >= fim )
        return;
    int posicao = particiona(vetor, inicio, fim, bench);

    quickSort(vetor, inicio, posicao - 1, bench);
    quickSort(vetor, posicao, fim, bench);
}