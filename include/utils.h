#ifndef UTILS_H
#define UTILS_H

// Funções utilitárias são adicionadas aqui conforme necessárias.

// ===============FUNÇÕES UTILIZADAS NA MAIN=============== //

// Aloca um vetor de "tamanho" inteiros. Encerra o programa
// (exit(1)) se a alocação falhar.
int* gerarVetor(int tamanho);

// Preenche o vetor com "tamanho" valores inteiros aleatórios. 
void vetorAleatorio(int *vetor, int tamanho);

// Preenche o vetor com "tamnho" valores inteiros em ordem crescente.
void vetorOrdenado(int *vetor, int tamanho);

// Preenche o vetor com "tamanho" valores inteiros em ordem decrescente.
void vetorInvertido(int *vetor, int tamanho);

// Imprime um cabeçalho com a mensagem do parâmetro.
// Usada para separar visualmente seções
void imprimeCabecalho(const char *titulo);

// Converte um número (long long) para string, escrevendo o resultado em
// "destino". "tamanho_destino" é o tamanho do buffer de destino, usado
// para evitar overflow durante a conversão.
void numberForString(long long numero, char* destino, size_t tamanho_destino);

// Recebe uma string numerica em "origem" e escreve em "destino" a mesma 
// string formatada com pontos como separadores de milhar (ex: "4999950000"
// vira "4.999.950.000"). "destino" precisa ser um buffer maior que 
// "origem", ja que a formatação adiciona caracteres.
void formataString(const char *origem, char *destino);

// Exibe "mensagem" e le um numero inteiro do teclado. Repete a leitura 
// enquanto a entrada não for um valor inteiro válido, limpando o buffer a cada
// tentativa invalida para evitar loop infinito com scanf.
int lerInteiro(const char *mensagem);

// ======================================================== //

#endif