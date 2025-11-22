#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#define TAM 1000

using namespace std;

#include "tipos.h"
#include "metodos.h"

int main(){
    FilmeAssistido filmes[TAM];
    string baseDados = "baseDados.csv";
    int qtd = 0;
    int opcao;

    qtd = conectarBase(filmes, baseDados, TAM);
    menuFilmes(filmes, TAM, qtd, baseDados);
 
    return 0;
}   