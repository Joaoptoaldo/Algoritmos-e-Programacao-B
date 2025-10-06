#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/metodos.h"

int main() {
    char nomeArquivo[256];

    printf("Digite caminho e nome do arquivo: ");
    scanf("%255s", nomeArquivo); // lê o caminho (sem espaços)

    // testar se o arquivo existe
    if (existeArquivo(nomeArquivo)) {
        printf("Arquivo localizado com sucesso\n");
    } else {
        printf("Arquivo nao localizado\n");
        exit(0);
    }

    // receber o conteúdo do arquivo em uma string
    char *resposta = copiarArquivo2String(nomeArquivo);
    if (resposta == NULL) {
        printf("Erro ao ler o arquivo.\n");
        exit(1);
    }

   
    printf("\n%s\n", resposta);

    
    int quantidade_vogais = contarVogais(resposta);
    printf("Quantidade de vogais no arquivo: %d\n", quantidade_vogais);

    free(resposta);
    return 0;
}

