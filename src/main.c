#include <stdio.h>
#include "sorts.h"

int main(void) 
{
    int n;

    printf("====================================\n"  );
    printf("     B E N C H M A R K  S O R T\n"       );
    printf("====================================\n\n");

    printf("BUBBLE SORT\nESCOLHA O TAMANHO DO VETOR [INTEIRO]: ");
    scanf("%d", &n);

    int vetor[n];

    printf("DIGITE OS INDICES INTEIROS, FORA DE ORDEM\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("SEU VETOR: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", vetor[j]);
    }

    printf("\n\n");

    printf("AGORA ORDENADO: ");
    bubbleSort(vetor, n);
    for (int k = 0; k < n; k++) {
        printf("%d ", vetor[k]);
    }

    return 0;
}