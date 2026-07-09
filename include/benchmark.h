#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <time.h>

typedef struct {
    long comparacoes;
    long trocas;
    clock_t inicio;
    double tempo_segundos;
} Benchmark;

void benchmarkIniciar(Benchmark *bench);
void benchmarkFinalizar(Benchmark *bench);

#endif