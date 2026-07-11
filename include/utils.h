#ifndef UTILS_H
#define UTILS_H

int* gerarVetor(int tamanho);
void vetorAleatorio(int *vetor, int tamanho);
void vetorOrdenado(int *vetor, int tamanho);
void vetorInvertido(int *vetor, int tamanho);
void imprimeCabecalho(const char *titulo);
void numberForString(long long tamanho, char* destino, size_t tamanho_destino);
void formataString(const char *origem, char *destino);
// Funções utilitárias serão adicionadas aqui conforme forem necessárias.

#endif