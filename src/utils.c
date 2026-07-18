#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void imprimeCabecalho(const char *titulo){
    printf("====================================\n");
    printf("%s\n", titulo);
    printf("====================================\n\n");
}

void numberForString(long long numero, char* destino, size_t tamanho_destino){
    snprintf(destino, tamanho_destino, "%lld", numero);
}

void formataString(const char *origem, char *destino){
    int tamanho       = strlen(origem);
    int pontos        = (tamanho - 1) / 3;
    int tamanho_final = tamanho + pontos;

    destino[tamanho_final] = '\0';

    int j        = tamanho_final - 1;
    int contador = 0;

    for (int i = tamanho - 1; i >= 0; i--){
        destino[j] = origem[i];
        j--;
        contador++;

        if (contador == 3 && i != 0){
            destino[j] = '.';
            j--;
            contador = 0;
        }
    }
}

int lerInteiro(const char *mensagem){
    int valor;
    printf("%s", mensagem);

    while (scanf("%d", &valor) != 1){
        while (getchar() != '\n');
        printf("ENTRADA INVALIDA. DIGITE UM NUMERO INTEIRO: ");
    }
    return valor;
}