#include <sstream>
#include <fstream>
#include <locale>
#include <string>

void listarPessoas(Pessoa vetor[], int qtdPessoas){

    setlocale(LC_ALL, "");

    cout << "Listar pessoas..." << endl;
    for (int i = 0; i < qtdPessoas; i++){
        cout << "Nome: " << vetor[i].nome << endl;
        cout << "Email: "<< vetor[i].email << endl;
    }

    cout << "\n";
    cout << "Total de registros: " << qtdPessoas << endl;
    cout << "\n";
}

int cadastrarPessoa(Pessoa vetor[], int tamanho, int qtd_pessoas, string baseDados) {
    cout << "Cadastrar pessoas...\n";
 /*   if (qtd_pessoas == tamanho){
        cout << "Vetor cheio, nao e possivel cadastrar mais pessoas\n";
        return qtd_pessoas;
    }*/

    Pessoa novaPessoa;
    cout << "Nome: ";
    getline(cin, novaPessoa.nome);
    cout << "Email: ";
    getline(cin, novaPessoa.email);

    vetor[qtd_pessoas] = novaPessoa;
    qtd_pessoas++;

    // Atualiza o arquivo CSV
    ofstream arquivo(baseDados, ios::app);
    if (arquivo.is_open()) {
        arquivo << novaPessoa.nome << "," << novaPessoa.email << endl;
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
    }

    return qtd_pessoas;
}

void menu(Pessoa vetor[], int tamanho, int qtd_pessoas, string baseDados){
    int opcao;
    do{
        //system("cls");
        cout << "MENU\n";
        cout << "1 - Listar pessoas\n";
        cout << "2 - Cadastrar pessoas\n";
        cout << "3 - Sair\n";
        cin >> opcao;
        getchar();

        switch (opcao){
            case 1:
                listarPessoas(vetor, qtd_pessoas);
                break;            
            case 2:                
                qtd_pessoas = cadastrarPessoa(vetor, TAM, qtd_pessoas, baseDados);
                break;
            case 3:
                break;
            default:
                cout << "Opção invalida\n";
                break;
        }

    }while(opcao != 3);
}

void split(string vetor[], string str, string deli = " "){
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
         i++;
         start = end + deli.size();
        end = str.find(deli, start);
    }
    //vetor[i] = str.substr(start, end - start);
    vetor[i] = str.substr(start);
 }

int conectarBase(string baseDados, Pessoa vetor[], int tamanho){
    int qtd_pesssoas = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados);

    if (!procuradorArquivo) { //caso arquivo nao exista
        cout << "Arquivo inexistente!" << endl;
        exit(0);
    }
    if (qtd_pesssoas == tamanho){
        cout << "Arquivo inexistente!" << endl;
        exit(0);
    }

    //le o arquivo capturando as frases
    string linha;
    string vetorLinha[2]; //nome, email
    while (!procuradorArquivo.eof()) {
        getline(procuradorArquivo,linha); //lendo a linha inteira
        split(vetorLinha, linha, ",");
        vetor[qtd_pesssoas].nome = vetorLinha[0];   
        vetor[qtd_pesssoas].email = vetorLinha[1];
        qtd_pesssoas += 1;
 
    }

    procuradorArquivo.close();
    return qtd_pesssoas;
    
}

bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho) {
    if (*quantidadeNomes == tamanho) {
        return false; //lista lotada
    }

    bool encontrou = false;
    int i;
    for (i = 0; i < *quantidadeNomes; i++) {
        if (nome == listaNomes[i]) {
            encontrou = true;
            break;
        }
    }

    if (encontrou) { //se encontrou o nome, retorna falso pq nao conseguiu inserir
        return false;
    }

    *quantidadeNomes = *quantidadeNomes + 1;
    listaNomes[*quantidadeNomes] = nome;

    //ordenar a lista de nomes
    //...

    return true; //consegui inserir na lista
}

void exibirListaNomes(string listaNomes[], int quantidadeNomes) {
    for (int i = 0; i < quantidadeNomes; i++) {
        cout << listaNomes[i] << endl;
    }
}

// int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho) {
//     ifstream procuradorArquivo; //tipo de arquivo para leitura
//     procuradorArquivo.open(nomeBaseDados); 

//     string linha;
//     int quantidadeNomes = 0;
//     while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
// 		getline(procuradorArquivo,linha); //lendo a linha inteira
//         listaNomes[quantidadeNomes] = linha; //a linha tem um nome completo
//         quantidadeNomes++;
// 	}
  
//     procuradorArquivo.close();

//     return quantidadeNomes;
// }


int contarVogais(string frase) {
    int totalVogais = 0;

    for (int i = 0; i < frase.size(); i++) {
        //cout << frase[i] << endl;
        if (frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' || 
            frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u'){
                totalVogais+=1; //totalVogais++;
        }
    }

    return totalVogais;
}

string trocarCaracter(string frase, char letra) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
    return frase;
}

string trocarCaracterOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for (int i = 0; i < frase.size(); i++) {
        if (toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
    return frase;
}

int contarPalavras(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;
    
    // Enquanto houver palavras na frase
    while (stream >> palavra) {
        cout << palavra << endl;
        contagem++;
    }
    
    return contagem;
}

string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool existeArquivo(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 
    
    if (procuradorArquivo) { //caso arquivo exista
        procuradorArquivo.close();
        return true;
    } 
    return false; //caso arquivo nao exista
}

string copiarArquivo2String(string nomeArquivo) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo); 

    string resposta = "";
    string linha;
    while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		resposta = resposta + linha + "\n";
	}
  
    procuradorArquivo.close();

    return resposta;
}