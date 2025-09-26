/*fazer um programa que tenha um método que receba uma frase e retorne a quantidade de vogais presentes na frase.*/

#include <iostream>
#include <string>


using namespace std;

int contarVogais(string frase) {
    int cont = 0;
    for (int i = 0; i < frase.length(); i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cont++;
    }
    return cont;
}

int main() {
    string frase;

    cout << "Digite uma frase sem especos: ";
    cin >> frase;

    cout << "Quantidade de vogais: " << contarVogais(frase);

    return 0;
}

