#include<iostream>
#include<string>
#define TAM 10

using namespace std;

#include "tipos.h"
#include "metodos.h"


int main(){
    Pessoa vetor[TAM];
    int qtd_pessoas;
    string baseDados = "base.csv";

    qtd_pessoas = conectarBase(baseDados, vetor, TAM);
    menu(vetor, TAM, qtd_pessoas, baseDados);

    return 1;
}

