#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

typedef struct {
    string nomeCompleto;
    string sobreNome;
} Pessoa;


string extrairSobrenome(const string &nome) {
    size_t pos = nome.find_last_of(" ");
    if (pos == string::npos) {
        return nome; 
    }
    return nome.substr(pos + 1);
}

// módulo 1: ler nomes e exibir na tela
void lerNomesExibir(const string &arquivoOrigem) {
    ifstream entrada(arquivoOrigem);
    string nome;
    if (!entrada.is_open()) {
        cerr << "Erro ao abrir o arquivo de origem!" << endl;
        return;
    }
    cout << "Nomes do arquivo:" << endl;
    while (getline(entrada, nome)) {
        cout << nome << endl;
    }
    entrada.close();
}

// módulo 2: ler nomes, armazenar em vetor e salvar com sobrenome
void processarNomesComSobrenome(const string &arquivoOrigem, const string &arquivoDestino) {
    ifstream entrada(arquivoOrigem);
    ofstream saida(arquivoDestino);
    string nome;
    vector<Pessoa> pessoas;

    if (!entrada.is_open() || !saida.is_open()) {
        cerr << "Erro ao abrir arquivos!" << endl;
        return;
    }

    while (getline(entrada, nome)) {
        Pessoa p;
        p.nomeCompleto = nome;
        p.sobreNome = extrairSobrenome(nome);
        pessoas.push_back(p);
    }

    for (const auto &p : pessoas) {
        saida << p.nomeCompleto << "; " << p.sobreNome << endl;
    }

    entrada.close();
    saida.close();
}

// módulo 3: ler nomes, exibir e salvar com quantidade de caracteres
void processarNomesComTamanho(const string &arquivoOrigem, const string &arquivoDestino) {
    ifstream entrada(arquivoOrigem);
    ofstream saida(arquivoDestino);
    string nome;

    if (!entrada.is_open() || !saida.is_open()) {
        cerr << "Erro ao abrir arquivos!" << endl;
        return;
    }

    while (getline(entrada, nome)) {
        cout << nome << endl;
        saida << nome << "; " << nome.size() << " caracteres" << endl;
    }

    entrada.close();
    saida.close();
}

int main() {
    string origem = "nomes.txt";
    string destino1 = "saida_sobrenomes.txt";
    string destino2 = "saida_tamanho.txt";

    lerNomesExibir(origem);

    processarNomesComSobrenome(origem, destino1);

    processarNomesComTamanho(origem, destino2);

    cout << "Processamento concluido!" << endl;
    return 0;
}
