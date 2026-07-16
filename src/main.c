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
    char comparacoes_str[21], comparacoes_formatado[28];
    char trocas_str[21], trocas_formatado[28];

    numberForString(bench->comparacoes, comparacoes_str, sizeof(comparacoes_str));
    formataString(comparacoes_str, comparacoes_formatado);

    numberForString(bench->trocas, trocas_str, sizeof(trocas_str));
    formataString(trocas_str, trocas_formatado);

    printf("COMPARACOES: %s\n", comparacoes_formatado);
    printf("TROCAS: %s\n", trocas_formatado);
    printf("TEMPO: %lf SEGUNDOS\n", bench->tempo_segundos);
}

int main(void){
    int n, opcaoAlgoritmo, opcaoTipo, continuar;
    srand(time(NULL));

    do{
        imprimeCabecalho("     B E N C H M A R K  S O R T");

        printf("ESCOLHA UM ALGORITMO:\n");
        printf("[1] Bubble Sort\n");
        printf("[2] Selection Sort\n");
        printf("[3] Insertion Sort\n");
        printf("[4] Merge Sort\n");
        printf("[5] Quick Sort\n");
        printf("\n[0] Para Encerrar\n\n");

        do{ // VERIFICA ENTRADA DO TIPO DO ALGORITMO DE ORDENAÇÃO
            opcaoAlgoritmo = lerInteiro("Opcao [0 a 5]: ");
        } while (opcaoAlgoritmo < 0 || opcaoAlgoritmo > 5);

        if (opcaoAlgoritmo == 0)
            break;

        do { // VERIFICA ENTRADA DO TAMANHO DO VETOR
            n = lerInteiro("\nDIGITE O TAMANHO DO VETOR (ENTRE 2 E 100 MIL): ");
        } while (n < TAMANHO_MIN || n > TAMANHO_MAX);

        printf("\nEscolha o tipo de vetor:\n");
        printf("[1] Aleatorio\n");
        printf("[2] Ordenado\n");
        printf("[3] Invertido\n");

        do { // VERIFICA ENTRADA DO TIPO DE VETOR
            opcaoTipo = lerInteiro("Opcao [1 a 3]: ");
        } while (opcaoTipo < 1 || opcaoTipo > 3);

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
        }
        imprimeCabecalho("     V E T O R  O R I G I N A L");
        imprimeVetor(vetor, n);
        printf("ORDENANDO ... AGUARDE ...\n");

        Benchmark bench;
        
        const char *nomeAlgoritmo;

        switch (opcaoAlgoritmo){
            case 1:
                benchmarkIniciar(&bench);     // zera contadores e marca o clock() inicial
                bubbleSort(vetor, n, &bench); // ordena e vai incrementando bench->comparacoes / bench->trocas
                benchmarkFinalizar(&bench);   // calcula quanto tempo passou
                nomeAlgoritmo = "        B U B B L E  S O R T";
                break;
            case 2:
                benchmarkIniciar(&bench);        // zera contadores e marca o clock() inicial
                selectionSort(vetor, n, &bench); // ordena e vai incrementando bench->comparacoes / bench->trocas
                benchmarkFinalizar(&bench);      // calcula quanto tempo passou               
                nomeAlgoritmo = "     S E L E C T I O N  S O R T";
                break;
            case 3:
                benchmarkIniciar(&bench);        // zera contadores e marca o clock() inicial
                insertionSort(vetor, n, &bench); // ordena e vai incrementando bench->comparacoes / bench->trocas
                benchmarkFinalizar(&bench);      // calcula quanto tempo passou
                nomeAlgoritmo = "     I N S E R T I O N  S O R T";
                break;
            case 4:
                benchmarkIniciar(&bench);
                mergeSort(vetor, 0, n - 1, &bench);
                benchmarkFinalizar(&bench);
                nomeAlgoritmo = "         M E R G E  S O R T";
                break;
            case 5:
                benchmarkIniciar(&bench);
                quickSort(vetor, 0, n - 1, &bench);
                benchmarkFinalizar(&bench);
                nomeAlgoritmo = "         Q U I C K  S O R T";
                break;
        }

        imprimeCabecalho("     V E T O R  O R D E N A D O");
        imprimeVetor(vetor, n);

        imprimeCabecalho(nomeAlgoritmo);
        imprimeBenchmark(&bench);

        free(vetor);
        printf("\n\n");
        continuar = lerInteiro("[1] Novamente / [0] Encerrar: ");
        printf("\n");
    } while (continuar);

    return 0;
}