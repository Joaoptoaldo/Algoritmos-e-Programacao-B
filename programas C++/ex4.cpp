/*fazer um programa que tenha um método que receba uma frase e retorne essa frase totalmente em maiúscula.*/

#include <iostream>
#include <string>

using namespace std;

string maiuscula(string frase) {
    for (int i = 0; i < frase.length(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

int main() {
    string frase;
    cout << "Digite uma frase sem espacos: ";
    cin >> frase;

    cout << "Frase em maiusculas: " << maiuscula(frase);

    return 0;
}

