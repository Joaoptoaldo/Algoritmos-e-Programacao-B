#include <sstream>
#include <fstream>
#include <string>
#include <metodos.h>
#include <iostream>

void split(string vetor[], string str, string deli = " ")
{        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

int conectarBase(string baseDados, Pessoa vetor[], int tamanho){
    int qtd_pesssoas = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados);

    if (!procuradorArquivo) { //caso arquivo nao exista
        cout << "Arquivo inexistente!" << endl;
        return 0;
    }
    if(qtd == tamanho){
        cout << "Arquivo inexistente!" << endl;
        return 0;
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

int conectarBase(string listaNomes[], string nomeBaseDados, int tamanho) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeBaseDados); 

    string linha;
    int quantidadeNomes = 0;
    while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        listaNomes[quantidadeNomes] = linha; //a linha tem um nome completo
        quantidadeNomes++;
	}
  
    procuradorArquivo.close();

    return quantidadeNomes;
}


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
