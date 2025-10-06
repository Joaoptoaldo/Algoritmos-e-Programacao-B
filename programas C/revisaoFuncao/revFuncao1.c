#include <stdio.h>
#include <string.h>
#include "utils/metodos.h"   // inclui sua fun��o 

int main() {
    char frase[250];  

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);  

    frase[strcspn(frase, "\n")] = '\0';

    // chama a fun��o que j� est� em metodos.h
    int quantidade_vogais = contarVogais(frase);

    printf("A frase tem %d vogais\n", quantidade_vogais);

    return 0;
}

