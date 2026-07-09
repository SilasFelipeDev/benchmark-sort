#include "sorts.h"

void bubbleSort(int *vetor, int tamanho, Benchmark *bench)
{
    int limite = tamanho;
    int troca  = 1;

    while (troca && limite > 1) {
        troca = 0;

        for (int i = 0; i < limite - 1; i++) {
            bench->comparacoes++;
            if (vetor[i] > vetor[i + 1]) {
                troca = 1;
                bench->trocas++;
                int aux      = vetor[i];
                vetor[i]     = vetor[i + 1];
                vetor[i + 1] = aux;
            }
        }
        limite--;
    }
}