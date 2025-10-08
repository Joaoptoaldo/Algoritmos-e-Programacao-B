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

    do {
        cout << "\n---- MENU GARAGEM ----\n";
        cout << "1) Entrada de veiculo\n";
        cout << "2) Listagem de veiculos\n";
        cout << "3) Saida de veiculo\n";
        cout << "4) Sair\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                qtd = entradaVeiculo(garagem, qtd, baseDados);
                break;
            case 2:
                listarVeiculos(garagem, qtd);
                break;
            case 3: {
                string placa;
                cout << "Placa do veiculo para saida: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, placa);
                qtd = saidaVeiculo(garagem, qtd, baseDados, placa);
                break;
            }
            case 4:
                break;
            default:
                cout << "Opção invalida!\n";
        }
    } while (opcao != 4);

    qtd = conectarBase(garagem, baseDados);
    
    return 0;
}   