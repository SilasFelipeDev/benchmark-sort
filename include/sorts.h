#ifndef SORTS_H
#define SORTS_H

#include "benchmark.h"

void bubbleSort(int *vetor, int tamanho, Benchmark *bench);
void selectionSort(int *vetor, int tamanho, Benchmark *bench);
void insertionSort(int *vetor, int tamanho, Benchmark *bench);
void mergeSort(int *vetor, int inicio, int fim, Benchmark *bench);

#endif