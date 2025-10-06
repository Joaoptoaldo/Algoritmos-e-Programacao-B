#include <stdio.h>
#include <string.h>

#include "utils/metodos.h"  

int main() {
    char frase[250];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    paraMaiusculo(frase);
    printf("Frase em maiúsculo: %s\n", frase);

    int totalPalavras = contarPalavras(frase);
    printf("Total de palavras na frase: %d\n", totalPalavras);

    return 0;
}
