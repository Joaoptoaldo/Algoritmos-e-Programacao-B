#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Registro {
    string glicose;
    int sono;
    string kcal;
    string carb;
    int padel;
};

int main() {
    ifstream arquivo("glicose_data.csv");
    string linha;
    vector<Registro> dados;

    // lê cabeçalho
    getline(arquivo, linha);

    // lê linha por linha
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        Registro r;
        string temp;

        getline(ss, r.glicose, ',');
        getline(ss, temp, ','); r.sono = stoi(temp);
        getline(ss, r.kcal, ',');
        getline(ss, r.carb, ',');
        getline(ss, temp, ','); r.padel = stoi(temp);

        dados.push_back(r);
    }

    cout << "Total de registros carregados: " << dados.size() << endl;
}

