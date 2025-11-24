#include <iostream>
#include <fstream>
#include <string>
#define TAM 1000

using namespace std;

#include "tipos.h"
#include "metodos.h"

int main(){
    FilmeAssistido filmes[TAM];
    string baseDados = "baseDados.csv";
    int qtd = 0;

    qtd = conectarBase(filmes, baseDados, TAM);//carrega os filmes do arquivo para o vetor e retorna a quantidade de filmes
    menuFilmes(filmes, TAM, qtd, baseDados);//chama o menu de filmes
 
    return 0;
}   