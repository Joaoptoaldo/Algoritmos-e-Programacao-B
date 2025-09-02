/*fazer um programa que tenha um método que receba um vetor de números inteiros, 
o tamanho desse vetor e retorne true se o vetor estiver ordenado ou false se o vetor estiver desordenado.*/

#include <iostream>
#include <string>

using namespace std;

bool estaOrdenado(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Digite o tamanho do vetor: ";
    cin >> n;

    int v[100]; 
    cout << "Digite os elementos do vetor:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (estaOrdenado(v, n))
        cout << "Vetor esta ordenado." << endl;
    else
        cout << "Vetor NAO esta ordenado." << endl;

    return 0;
}

