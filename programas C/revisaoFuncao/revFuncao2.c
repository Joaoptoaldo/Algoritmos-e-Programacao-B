#include <stdio.h>
#include <string.h>

#include "utils/metodos.h"  

int main() {
    char frase[250];
    char letra;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    printf("Digite a letra de pesquisa: ");
    scanf(" %c", &letra);  

    trocarCaracter(frase, letra);

    printf("Frase alterada: %s\n", frase);

    return 0;
}

