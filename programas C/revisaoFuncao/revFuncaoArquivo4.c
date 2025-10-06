#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/metodos.h"  // cont�m as fun��es existeArquivo() e copiarArquivo2String()

int main() {
    char nomeArquivo[256];

    printf("Digite caminho e nome do arquivo: ");
    scanf("%255s", nomeArquivo); // l� o nome do arquivo (sem espa�os)

    // testar se o arquivo existe
    if (existeArquivo(nomeArquivo)) {
        printf("Arquivo localizado com sucesso\n");
    } else {
        printf("Arquivo nao localizado\n");
        exit(0);
    }

    // receber o conte�do do arquivo em uma string
    char *resposta = copiarArquivo2String(nomeArquivo);

    if (resposta == NULL) {
        printf("Erro ao ler o arquivo.\n");
        exit(1);
    }

    printf("%s\n", resposta);

    // liberar mem�ria
    free(resposta);

    return 0;
}

