/*fazer um programa e dentro dele um método que receba uma palavra (do tipo string) e uma letra (do tipo char). 
O método deve contar quantas vezes a letra aparece na palavra e exibir essa quantidade;*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string palavra;
    char letra;

    cout << "Digite uma palavra: ";
    cin >> palavra;
    cout << "Digite uma letra: ";
    cin >> letra;

    contarLetra(palavra, letra);

    return 0;
}

void contarLetra(string palavra, char letra) {
    int cont = 0;
    for (int i = 0; i < palavra.length(); i++) {
        if (palavra[i] == letra) {
            cont++;
        }
    }
    cout << "A letra '" << letra << "' aparece " << cont << " vezes.";
}

