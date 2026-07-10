#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "benchmark.h"
#include "utils.h"

#define TAMANHO_MIN 2
#define TAMANHO_MAX 100000

void imprimeVetor(int *vetor, int tamanho){
    int colunas = 10;  // quantos números por linha
    int limite  = 100; // quantos indices do vetor vão aparecer

    if (tamanho <= limite){
        for (int i = 0; i < tamanho; i++) {
            printf("%7d ", vetor[i]);
            if ((i + 1) % colunas == 0){
                printf("\n");
            }
        }
        printf("\n");
        return;
    }
    // Primeiros 50
    for (int i = 0; i < 50; i++){
        printf("%7d ", vetor[i]);
        if ((i + 1) % colunas == 0){
            printf("\n");
        }
    }
    printf("\n  [...] VETOR TRUNCADO PARA MELHOR VIZUALIZACAO\n\n");
    // Ultimos 50
    int inicio = tamanho - 50;
    for (int i = inicio; i < tamanho; i++){
        printf("%7d ", vetor[i]);
        if ((i - inicio + 1) % colunas == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void imprimeBenchmark(Benchmark *bench){
    printf("\COMPARACOES: %lld\n", bench->comparacoes);
    printf("TROCA: %lld\n", bench->trocas);
    printf("TEMPO: %lf SEGUNDOS\n", bench->tempo_segundos);
}

int main(void) 
{
    int n, opcaoAlgoritmo, opcaoTipo;
    srand(time(NULL));

    printf("====================================\n"  );
    printf("     B E N C H M A R K  S O R T\n"       );
    printf("====================================\n\n");

    printf("Escolha um Algoritmo:\n");
    printf("[1] Bubble Sort\n");
    printf("[2] Selection Sort\n");
    printf("[3] Insertion Sort\n");
    printf("Opcao: ");
    scanf("%d", &opcaoAlgoritmo);

    do {
        printf("\nDIGITE O TAMANHO DO VETOR (ENTRE %d E 100 MIL): ", TAMANHO_MIN);
        scanf("%d", &n);

    } while (n < TAMANHO_MIN || n > TAMANHO_MAX);

    printf("\nEscolha o tipo de vetor:\n");
    printf("[1] Aleatorio\n");
    printf("[2] Ordenado\n");
    printf("[3] Invertido\n");
    printf("Opcao: ");
    scanf("%d", &opcaoTipo);

    int *vetor = gerarVetor(n);

    switch (opcaoTipo){
        case 1:
            vetorAleatorio(vetor, n);
            break;
        case 2:
            vetorOrdenado(vetor, n);
            break;
        case 3:
            vetorInvertido(vetor, n);
            break;
        default: 
            printf("\nOpcao invalida.\n");
            return 1;
    }
    printf("====================================\n");
    printf("     V E T O R  O R I G I N A L     \n");
    printf("====================================\n");
    imprimeVetor(vetor, n);

    Benchmark bench;

    switch (opcaoAlgoritmo){
        case 1:
            printf("====================================\n");
            printf("        B U B B L E  S O R T        \n");
            printf("====================================\n");
            benchmarkIniciar(&bench);     // zera contadores e marca o clock() inicial
            bubbleSort(vetor, n, &bench); // ordena e vai incrementando bench->comparacoes / bench->trocas
            benchmarkFinalizar(&bench);   // calcula quanto tempo passou
            break;
        case 2:
            printf("====================================\n");
            printf("     S E L E C T I O N  S O R T     \n");
            printf("====================================\n");
            benchmarkIniciar(&bench);        // zera contadores e marca o clock() inicial
            selectionSort(vetor, n, &bench); // ordena e vai incrementando bench->comparacoes / bench->trocas
            benchmarkFinalizar(&bench);      // calcula quanto tempo passou               
            break;
        case 3:
            printf("====================================\n");
            printf("     I N S E R T I O N  S O R T     \n");
            printf("====================================\n");
            benchmarkIniciar(&bench);        // zera contadores e marca o clock() inicial
            insertionSort(vetor, n, &bench); // ordena e vai incrementando bench->comparacoes / bench->trocas
            benchmarkFinalizar(&bench);      // calcula quanto tempo passou
            break;
        default:
            printf("\nOpcao invalida.\n");
            return 1;
    }

    printf("====================================\n");
    printf("     V E T O R  O R D E N A D O     \n");
    printf("====================================\n");
    imprimeVetor(vetor, n);

    imprimeBenchmark(&bench);

    free(vetor);
    return 0;
}