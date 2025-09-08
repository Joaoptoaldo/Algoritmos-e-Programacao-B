#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estruturas para armazenar dados
struct Paciente {
    string nome;
    char sexo; // M ou F
    string dataNascimento;
    float altura;
    float peso;
    int pontuacao; // Pontos da triagem
};

struct Profissional {
    string nome;
    string funcao; // M�dico, enfermeiro, etc
};

struct UnidadeAtendimento {
    string nome;
    string endereco;
};

// Fun��o para calcular urg�ncia com base na pontua��o
string calcularUrgencia(int pontuacao) {
    if (pontuacao >= 10)
        return "Alta urg�ncia";
    else if (pontuacao >= 5)
        return "M�dia urg�ncia";
    else
        return "Baixa urg�ncia";
}

// Fun��o para triagem de sintomas
int triagemSintomas() {
    int pontuacao = 0;
    char resposta;

    cout << "Responda com S para sim ou N para n�o aos sintomas abaixo:\n";

    cout << "Febre: ";
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') pontuacao += 3;

    cout << "Dores musculares: ";
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') pontuacao += 2;

    cout << "Coriza: ";
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') pontuacao += 1;

    cout << "V�mito: ";
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') pontuacao += 2;

    cout << "Tosse: ";
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') pontuacao += 2;

    cout << "Falta de ar: ";
    cin >> resposta;
    if (resposta == 'S' || resposta == 's') pontuacao += 3;

    return pontuacao;
}

// Fun��o para cadastrar paciente
Paciente cadastrarPaciente() {
    Paciente p;
    cout << "Nome do paciente: ";
    cin.ignore(); // limpar buffer
    getline(cin, p.nome);

    cout << "Sexo (M/F): ";
    cin >> p.sexo;

    cout << "Data de nascimento (DD/MM/AAAA): ";
    cin >> p.dataNascimento;

    cout << "Altura (m): ";
    cin >> p.altura;

    cout << "Peso (kg): ";
    cin >> p.peso;

    // Triagem de sintomas
    cout << "\n--- Triagem de sintomas ---\n";
    p.pontuacao = triagemSintomas();

    cout << "\nPaciente cadastrado com urg�ncia: " << calcularUrgencia(p.pontuacao) << endl;

    return p;
}

// Fun��o principal com menu
int main() {
    vector<Paciente> pacientes;
    vector<Profissional> profissionais;
    vector<UnidadeAtendimento> unidades;

    int opcao;

    do {
        cout << "\n--- Sistema de Triagem COVID ---\n";
        cout << "1. Cadastrar paciente\n";
        cout << "2. Listar pacientes\n";
        cout << "3. Cadastrar profissional de sa�de\n";
        cout << "4. Listar profissionais\n";
        cout << "5. Cadastrar unidade de atendimento\n";
        cout << "6. Listar unidades\n";
        cout << "0. Sair\n";
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch(opcao) {
            case 1: {
                Paciente p = cadastrarPaciente();
                pacientes.push_back(p);
                break;
            }
            case 2: {
                cout << "\n--- Lista de pacientes ---\n";
                for (int i = 0; i < pacientes.size(); i++) {
                    cout << i+1 << ". " << pacientes[i].nome 
                         << " | Sexo: " << pacientes[i].sexo
                         << " | Nascimento: " << pacientes[i].dataNascimento
                         << " | Altura: " << pacientes[i].altura
                         << " | Peso: " << pacientes[i].peso
                         << " | Urg�ncia: " << calcularUrgencia(pacientes[i].pontuacao) << endl;
                }
                break;
            }
            case 3: {
                Profissional prof;
                cout << "Nome do profissional: ";
                cin.ignore();
                getline(cin, prof.nome);
                cout << "Fun��o: ";
                getline(cin, prof.funcao);
                profissionais.push_back(prof);
                break;
            }
            case 4: {
                cout << "\n--- Lista de profissionais ---\n";
                for (int i = 0; i < profissionais.size(); i++) {
                    cout << i+1 << ". " << profissionais[i].nome
                         << " | Fun��o: " << profissionais[i].funcao << endl;
                }
                break;
            }
            case 5: {
                UnidadeAtendimento u;
                cout << "Nome da unidade: ";
                cin.ignore();
                getline(cin, u.nome);
                cout << "Endere�o: ";
                getline(cin, u.endereco);
                unidades.push_back(u);
                break;
            }
            case 6: {
                cout << "\n--- Lista de unidades ---\n";
                for (int i = 0; i < unidades.size(); i++) {
                    cout << i+1 << ". " << unidades[i].nome
                         << " | Endere�o: " << unidades[i].endereco << endl;
                }
                break;
            }
            case 0: 
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Op��o inv�lida! Tente novamente.\n";
        }

    } while(opcao != 0);

    return 0;
}

