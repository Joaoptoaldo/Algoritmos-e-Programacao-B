#ifndef MEUS_METODOS_H
#define MEUS_METODOS_H

#include <stdbool.h>

// Conta o número de vogais em uma frase
int contarVogais(const char *frase);

// Substitui todas as ocorrências de 'letra' por '@' na frase
void trocarCaracter(char *frase, char letra);

// Substitui todas as ocorrências de 'letraOrigem' por 'letraDestino' na frase
void trocarCaracterOrigemDestino(char *frase, char letraOrigem, char letraDestino);

// Conta o número de palavras em uma frase
int contarPalavras(const char *frase);

// Converte uma frase para maiúsculas
void paraMaiusculo(char *frase);

// Verifica se o arquivo existe
bool existeArquivo(const char *nomeArquivo);

// Lê o conteúdo de um arquivo e retorna como string alocada dinamicamente
char* copiarArquivo2String(const char *nomeArquivo);

#endif

