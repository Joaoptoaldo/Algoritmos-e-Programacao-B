#include <iostream>
#include <string>
#define TAM 5
using namespace std;
 
typedef struct {
    string placa;
    string horaEntrada;
    string horaSaida;
    float valor;
} Carro;
 
int main() {
    Carro garagem[TAM];
    Carro carro;
    int quantidadeCarros = 0;
    int opcao = 1;
 
    while (opcao != 4) {
        system("cls");
        cout << "M E N U\n";
        cout << "1 - Entra carro\n";
        cout << "2 - Sai carro\n";
        cout << "3 - Lista carros\n";
        cout << "4 - Fim\n";
        cout << "Opcao: ";
        cin >> opcao;
 
        switch (opcao) {
            case 1:
    cout << "Entrada do carro na garagem....\n";
    if (quantidadeCarros == TAM) {
        cout << "Nao ha vagas na garagem....\n";
    } else {
        cout << "Placa: ";
        cin >> carro.placa;

        //verificação se o carro (placa) já está na garagem
        bool carroJaExiste = false;
        for (int i = 0; i < quantidadeCarros; i++) {
            if (garagem[i].placa == carro.placa) {
                carroJaExiste = true;
                break;
            }
        }

        if (carroJaExiste) {
            cout << "Este carro ja esta na garagem!\n";
        } else {
            cout << "Hora de entrada: ";
            cin >> carro.horaEntrada;

            garagem[quantidadeCarros] = carro;
            quantidadeCarros++;
            cout << "Imprimindo o ticket....\n";
        }
    }
    break;

            case 2:
                cout << "Saindo carro na garagem....\n";
                break;
            case 3:
                cout << "Listagem de carros na garagem....\n";
                if (quantidadeCarros == 0) {
                    cout << "Nao ha carros na garagem ....\n";
                } else {
                    for (int i = 0; i < quantidadeCarros; i++) {
                        cout << "Carro com placa: " << garagem[i].placa << ". Hora entrada: " << garagem[i].horaEntrada << "\n";
                    }
                }
                break;
            case 4:
                cout << "Obrigado por usar o sistema....\n";
                break;
            default:
                cout << "Opcao invalida.....\n";
                break;
        }
        system("pause");
    }
 
    return 1;
}

 

