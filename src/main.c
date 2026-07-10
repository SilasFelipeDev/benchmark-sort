#include <stdio.h>
#include "sorts.h"
#include "benchmark.h"

void imprimeVetor(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void imprimeBenchmark(Benchmark *bench){
    printf("\nComparacoes: %ld\n", bench->comparacoes);
    printf("Trocas: %ld\n", bench->trocas);
    printf("Tempo: %lf segundos\n", bench->tempo_segundos);
}

int main(void) 
{
    int n, opcao;

    printf("====================================\n"  );
    printf("     B E N C H M A R K  S O R T\n"       );
    printf("====================================\n\n");

    printf("Escolha um Algoritmo:\n");
    printf("[1] Bubble Sort\n");
    printf("[2] Selection Sort\n");
    printf("[3] Insertion Sort\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\nDIGITE O TAMANHO DO VETOR [INTEIRO]: ");
    scanf("%d", &n);

    int vetor[n];

    printf("\nDIGITE OS INDICES INTEIROS, FORA DE ORDEM:\n");
    for (int i = 0; i < n; i++) {
        printf("INDICE [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\nVETOR ORIGINAL:\n");
    imprimeVetor(vetor, n);

    Benchmark bench;

    switch (opcao){
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

    printf("\nVETOR ORDENADO:\n");
    imprimeVetor(vetor, n);

    imprimeBenchmark(&bench);

    return 0;
}