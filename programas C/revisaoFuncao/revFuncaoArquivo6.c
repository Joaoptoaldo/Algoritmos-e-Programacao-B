#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/metodos.h"  

int main() {
    char nomeArquivo[256];
    char letraOrigem, letraDestino;

    printf("Digite caminho e nome do arquivo: ");
    scanf(" %255[^\n]", nomeArquivo);  

    if (existeArquivo(nomeArquivo)) {
        printf("Arquivo localizado com sucesso\n");
    } else {
        printf("Arquivo nao localizado\n");
        exit(0);
    }

  
    char *resposta = copiarArquivo2String(nomeArquivo);
    if (resposta == NULL) {
        printf("Erro ao ler o arquivo.\n");
        exit(1);
    }

    printf("\nConteúdo original:\n%s\n", resposta);

    printf("Digite a letra origem: ");
    scanf(" %c", &letraOrigem);

    printf("Digite a letra destino: ");
    scanf(" %c", &letraDestino);

    // trocar caracteres
    trocarCaracterOrigemDestino(resposta, letraOrigem, letraDestino);

    printf("\nResposta alterada:\n%s\n", resposta);

    free(resposta); 

    return 0;
}

