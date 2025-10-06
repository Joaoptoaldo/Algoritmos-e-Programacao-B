#include<iostream>
#include<string>
#define TAM 1000

using namespace std;

#include "tipos.h"
#include "metodos.h"


int main(){
    Pessoa vetor[TAM];
    int qtd_pessoas = 0;
    string baseDados = "base_dados.csv";

    conectarBase(baseDados, vetor, &qtd_pessoas, TAM);
    menu(vetor, TAM, qtd_pessoas);

    for(int i=0; i<qtd_pessoas; i++){
        cout << vetor[i].nome << " - " << vetor[i].email << endl;
    }


    return 1;
}

