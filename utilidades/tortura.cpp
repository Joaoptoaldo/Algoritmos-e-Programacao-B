/*
- Desafio avaliativo:
    Combinar os programas da Garagem e o da aula, refatorando-os de forma que toda a placa de carro que entre na garagem, além de ser salva no vetor/lista/garagem, também seja salva no arquivo.
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
       - 1) Entrada veiculo (digitar a placa e a data de entrada, mas pode-se capturar do sistema. Inserir no vetor e no arquivo)
      -  2) Listagem veiculos
        3) Saida veiculo (digitar a placa e retirar da garagem, tanto vetor, quanto arquivo
        4) Fim programa*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

#include "metodos.h"
#include "tipos.h"

#define TAM 10


//main
int main(){
    Veiculo garagem[TAM];
    string baseDados = "garagem.csv";
    int qtd = 0;
    int opcao;

     do {
        cout << "\n---- MENU GARAGEM ----\n";
        cout << "1) Entrada de veículo\n";
        cout << "2) Listagem de veículos\n";
        cout << "3) Saída de veículo\n";
        cout << "4) Fim\n";
        cout << "Escolha: ";
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
                cout << "Placa do veículo para saída: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, placa);
                qtd = saidaVeiculo(garagem, qtd, baseDados, placa);
                break;
            }
            case 4:
                cout << "Encerrando programa...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (opcao != 4);

    qtd = conectarBase(garagem, baseDados);
    
    return 0;
}
//3) Saida veiculo (digitar a placa e retirar da garagem, tanto vetor, quanto arquivo
    