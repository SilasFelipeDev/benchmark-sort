#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int* gerarVetor(int tamanho){
    int *vetor = (int *) malloc(tamanho * sizeof(int));

    if (vetor == NULL){
        printf("Erro: Memoria insuficiente!\n");
        exit(1);
    }
    return vetor;
}

void vetorAleatorio(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 1001;
    }
}

void vetorOrdenado(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = i;
    }
}

void vetorInvertido(int *vetor, int tamanho){
    int indice = tamanho - 1;
    for (int i = 0; i < tamanho; i++){
        vetor[i] = indice;
        indice--;
    }
}