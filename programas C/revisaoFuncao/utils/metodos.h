#ifndef MEUS_METODOS_H
#define MEUS_METODOS_H

#include <stdbool.h>   

// Conta o n�mero de vogais em uma frase
int contarVogais(const char *frase);

// Substitui todas as ocorr�ncias de 'letra' por '@' na frase
void trocarCaracter(char *frase, char letra);

// Substitui todas as ocorr�ncias de 'letraOrigem' por 'letraDestino' na frase
void trocarCaracterOrigemDestino(char *frase, char letraOrigem, char letraDestino);

// Conta o n�mero de palavras em uma frase
int contarPalavras(const char *frase);

// Converte uma frase para mai�sculas
void paraMaiusculo(char *frase);

// Verifica se o arquivo existe
bool existeArquivo(const char *nomeArquivo);

// L� o conte�do de um arquivo e retorna como string alocada dinamicamente
char* copiarArquivo2String(const char *nomeArquivo);

#endif

