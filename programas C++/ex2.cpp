/*fazer um programa e dentro dele um método que receba o dia (string), o mês (string) e o ano (string). 
O método deve escrever 'DATA VÁLIDA' ou 'DATA INVÁLIDA' para a situação das variáveis passadas.*/

#include <iostream>
#include <string>


using namespace std;

void validarData(int d, int m, int a) {
    bool valida = true;

    if (m < 1 || m > 12) {
        valida = false;
    } else {
        int diasMes;
        if (m == 2) {
            bool bissexto = (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
            diasMes = bissexto ? 29 : 28;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            diasMes = 30;
        }
        else {
            diasMes = 31;
        }

        if (d < 1 || d > diasMes) valida = false;
    }

    if (valida)
        cout << "DATA VALIDA" << endl;
    else
        cout << "DATA INVALIDA" << endl;
}

int main() {
    int dia, mes, ano;

    cout << "Digite o dia: ";
    cin >> dia;
    cout << "Digite o mes: ";
    cin >> mes;
    cout << "Digite o ano: ";
    cin >> ano;

    validarData(dia, mes, ano);

    return 0;
}



