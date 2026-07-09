#include "benchmark.h"

/*
ZERA TUDO E MARCA "O PONTO DE PARTIDA DO CRONÔMETRO - 
DEVE SER CHAMADA LOGO ANTES DA ORDENAÇÃO
*/
void benchmarkIniciar(Benchmark *bench){
    bench->comparacoes    = 0;
    bench->trocas         = 0;
    bench->tempo_segundos = 0.0;
    bench->inicio         = clock();
}

/*
CALCULA QUANTO TEMPO PASSOU, CONVERTENDO DE "TIC-TAC" DE CLOCK PARA
SEGUNDOS (CLOCKS_PER_SEC É UMA CONSTANTE DA PRÓPRIA time.h).
*/
void benchmarkFinalizar(Benchmark *bench){
    clock_t fim = clock();
    bench->tempo_segundos = (double)(fim - bench->inicio) / CLOCKS_PER_SEC;
}