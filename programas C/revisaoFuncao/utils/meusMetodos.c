#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "metodos.h"

// Conta o número de vogais em uma frase
int contarVogais(const char *frase) {
    int totalVogais = 0;
    for (int i = 0; frase[i] != '\0'; i++) {
        char c = frase[i];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            totalVogais++;
        }
    }
    return totalVogais;
}

// Substitui todas as ocorrências de 'letra' por '@'
void trocarCaracter(char *frase, char letra) {
    for (int i = 0; frase[i] != '\0'; i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
}

// Substitui todas as ocorrências de 'letraOrigem' por 'letraDestino'
void trocarCaracterOrigemDestino(char *frase, char letraOrigem, char letraDestino) {
    for (int i = 0; frase[i] != '\0'; i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
}

// Conta o número de palavras em uma frase
int contarPalavras(const char *frase) {
    int contagem = 0;
    int dentroPalavra = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        if (!isspace(frase[i])) {
            if (!dentroPalavra) {
                contagem++;
                dentroPalavra = 1;
            }
        } else {
            dentroPalavra = 0;
        }
    }

    return contagem;
}

// Converte uma frase para maiúsculas
void paraMaiusculo(char *frase) {
    for (int i = 0; frase[i] != '\0'; i++) {
        frase[i] = toupper(frase[i]);
    }
}

// Verifica se o arquivo existe
bool existeArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo != NULL) {
        fclose(arquivo);
        return true;
    }
    return false;
}

// Lê o conteúdo de um arquivo e retorna como string alocada dinamicamente
char* copiarArquivo2String(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) return NULL;

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    char *conteudo = (char*)malloc(tamanho + 1);
    if (conteudo == NULL) {
        fclose(arquivo);
        return NULL;
    }

    fread(conteudo, 1, tamanho, arquivo);
    conteudo[tamanho] = '\0';

    fclose(arquivo);
    return conteudo;
}

