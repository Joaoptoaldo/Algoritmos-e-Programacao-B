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
    string dataEntrada;
    string modelo;
    string fabricante;
    string proprietario;
    string comentario;
} Veiculo;

typedef struct {
    std::string dataAssistido;
    std::string tituloFilme;
    int nota;
    std::string diretor;
    std::string comentario;
} FilmeAssistido;