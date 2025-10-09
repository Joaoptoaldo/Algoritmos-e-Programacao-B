/*
    1) struct:
    ```
    typedef struct {
        string placa;
        string dataEntrada;
    } Veiculo;
    ```
    2) garagem é um vetor de TAM veiculos:
    ```
    Veiculo garagem[TAM];
    ```
    3) Menu (antes de executar o menu, conectarBase)
        1) Entrada veiculo (digitar a placa e a data de entrada, mas pode-se capturar do sistema. Inserir no vetor e no arquivo)
        2) Listagem veiculos
        3) Saida veiculo (digitar a placa e retirar da garagem, tanto vetor, quanto arquivo
        4) Fim programa
*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#define TAM 10

using namespace std;

#include "tipos.h"
#include "metodos.h"

int main(){
    Veiculo garagem[TAM];
    string baseDados = "garagem.csv";
    int qtd = 0;
    int opcao;


    qtd = conectarBase(garagem, baseDados);
    menuGaragem(garagem, TAM, qtd, baseDados);

    
    return 0;
}   