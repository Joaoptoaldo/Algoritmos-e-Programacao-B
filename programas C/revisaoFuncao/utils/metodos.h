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


void trocarCaracter(char *frase, char letra) {
    for (int i = 0; frase[i] != '\0'; i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
}


void trocarCaracterOrigemDestino(char *frase, char letraOrigem, char letraDestino) {
    for (int i = 0; frase[i] != '\0'; i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
}


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


void paraMaiusculo(char *frase) {
    for (int i = 0; frase[i] != '\0'; i++) {
        frase[i] = toupper(frase[i]);
    }
}


bool existeArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo != NULL) {
        fclose(arquivo);
        return true;
    }
    return false;
}


char* copiarArquivo2String(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return NULL;
    }

    // Move para o fim para descobrir o tamanho
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    // Aloca memória para armazenar o conteúdo
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




