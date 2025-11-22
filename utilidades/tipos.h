#include <string>
#include <fstream>

typedef struct {
    int id;
    string nome;
    int data_nasc;
    string email;
    string telefone;
    string endereco;
} Pessoa;

typedef struct {
    string placa;
    string modelo;
    string cor;
    string fabricante;
    int ano_fabricacao;
    string proprietario;
    string dataEntrada;
    string dataSaida;
} Veiculo;

typedef struct {
    string dataAssistido;
    string tituloFilme;
    int nota;
    string diretor;
    string comentario;
} FilmeAssistido;