#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include<iostream>
#include <cctype>
#define TAM 1000
using namespace std;

#include "meusTipos.h"

void gravarPessoaBase(string nome, string email, string baseDados){
	ofstream procuradorArquivo; 
    procuradorArquivo.open(baseDados, ios::out | ios::app);
    procuradorArquivo << "\n"<< nome << "," << email << endl;
    procuradorArquivo.close();
}

int cadastrarPessoas(Pessoa vetor[], int qtdPessoas, int tamanho, string baseDados){
    if(tamanho == qtdPessoas){
        cout << "Estrutura de Dados lotada" << endl;
        return qtdPessoas;
    }

    string nome;
    string email;

    cout << "nome: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, nome);

    cout << "email: " << endl;
    cin >> email;

    vetor[qtdPessoas].nome = nome;
    vetor[qtdPessoas].email = email;
    qtdPessoas += 1;

    gravarPessoaBase(nome, email, baseDados);
    return qtdPessoas;
    
}
    void listarPessoas(Pessoa vetor[], int qtdPessoas){
    cout << "Listar Pessoas: " << endl;
    for(int i=0; i < qtdPessoas; i++){
        cout << "nome: "<< vetor[i].nome << endl;
        cout << "email: " << vetor[i].email << endl;
        cout << "_________________" << endl;
    }
    cout << "----------------\n";
    cout << "total de registros: " << qtdPessoas << endl;
}


void  menu(Pessoa vetor[], int tamanho, int qtdPessoas, string baseDados){
    int opcao;
    do{
        cout << "-- M E N U --\n";
        cout << "1 - listar pessoas" << endl;
        cout << "2 - cadastrar pessoa" << endl;
        cout << "3 - sair" << endl;
        cout << "opcao" << endl;
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (opcao)
        {
        case 1:
             listarPessoas(vetor, qtdPessoas);
                break;
        case 2:
            cout << "cadastrar Pessoa" << endl;
            qtdPessoas = cadastrarPessoas(vetor, qtdPessoas, tamanho, baseDados);
                break;
            case 3:
            cout << "sair" << endl;
                break;
        default:
            cout << "opcao invalida" << endl;
                break;
        }

    }while (opcao != 3);
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
    vetor[i] = str.substr(start, end - start);
}



int conectarBase(string arquivo, Pessoa vetor[], int tamanho){
    int qtdPessoas = 0;
    ifstream procuradorArquivo;   
    procuradorArquivo.open(arquivo);

    if(!procuradorArquivo){
        cout << "arquivo de base de dados não localizado" << endl;
        exit(0);
    }
    if(qtdPessoas == tamanho){
        cout << "vetor lotado. Programa Encerrado" << endl;
        exit(0);
    }

    string linha;
    string vetorLinha[2];
	while (getline(procuradorArquivo, linha)) {
        if(linha.empty()) continue; 
 
        //linha = Lucas Camargo, camargo.lucas@ufn.edu.br
        split(vetorLinha, linha, ",");
        //vetorLinha[0] = "Lucas Camargo" vetorLinha[1] = camargo.lucas@ufn.edu.br
        vetor[qtdPessoas].nome = vetorLinha[0];
        vetor[qtdPessoas].email = vetorLinha[1];
        qtdPessoas += 1;
    } 
    procuradorArquivo.close();

    return qtdPessoas;
}

void cabecalhoMenu() {
    system("clear"); 
    cout << "=============================================\n";
    cout << "|         SISTEMA DE GESTAO DE GARAGEM      |\n";
    cout << "=============================================\n";
    cout << "|          1 - Listar veiculos              |\n";
    cout << "|          2 - Cadastrar entrada            |\n";
    cout << "|          3 - Registrar saida              |\n";
    cout << "|          4 - Mostrar status da garagem    |\n";
    cout << "|          5 - Encerrar programa            |\n";
    cout << "---------------------------------------------\n";
    cout << "Escolha uma opcao: ";
}

void mostrarStatus(int qtdCarros, int capacidade) {
    int vagasLivres = capacidade - qtdCarros;
    float ocupacao = 0.0;
    if (capacidade > 0) { 
        ocupacao = (float)qtdCarros / capacidade * 100;
    }

    cout << "\nStatus atual da garagem:\n";
    cout << "---------------------------------------------\n";
    cout << "Total de vagas: " << capacidade << endl;
    cout << "Veiculos estacionados: " << qtdCarros << endl;
    cout << "Vagas disponiveis: " << vagasLivres << endl;
    cout << fixed << setprecision(1);
    cout << "Taxa de ocupacao: " << ocupacao << "%\n";
    cout << "---------------------------------------------\n";
}


void placaParaMaiusculo(string& placa) {
   for(char& ch: placa){
    ch = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
   }
}

void gravarCarroBase(string placa, string dataEntrada, string baseDados){
    ofstream procuradorArquivo(baseDados, ios::out | ios::app);
    if(!procuradorArquivo){
        cout << "Nao foi possivel acessar o arquivo para gravar a entrada.\n";
        return;
    }
    procuradorArquivo << placa << "," << dataEntrada << "\n";
}

void salvarGaragemBase(const string& baseDados, Veiculo garagem[], int qtdCarros){
    ofstream out(baseDados, ios::out | ios::trunc);
    if(!out){
        cout << "Nao foi possivel salvar o estado atual da garagem" << endl;
        return;
    }
    for(int i=0; i< qtdCarros;++i){
        if(garagem[i].placa.empty()) continue;
        out << garagem[i].placa << "," << garagem[i].dataEntrada << endl;
    }
}
int conectarBaseVeiculos(const string& arquivo, Veiculo garagem[], int tamanho){
    int qtdCarros = 0;
    ifstream procuradorArquivo(arquivo);
    if(!procuradorArquivo){
        cout << "Base de veiculos nao localizada.\n";
        return 0;
    }
    if(qtdCarros == tamanho){
        cout << "Garagem lotada." << endl;
        exit(0);
    }

    string linha;
    string vetorLinha[2];
	while (getline(procuradorArquivo, linha)) {

        split(vetorLinha, linha, ",");
        string placa = vetorLinha[0];
        string data = vetorLinha[1];

        if(placa.empty()) continue;

        placaParaMaiusculo(placa);

        garagem[qtdCarros].placa = placa;
        garagem[qtdCarros].dataEntrada = data;
        qtdCarros++;

       
    } 
    procuradorArquivo.close();

    return qtdCarros;
}

int cadastrarCarros(Veiculo garagem[], int qtdCarros, int tamanho, string baseDados){
    if(tamanho == qtdCarros){
        cout << "Estrutura de dados cheia." << endl;
        return qtdCarros;
    }

    string placa, dataEntrada;

    cout << "placa(LLLNLNNN): " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, placa);

    placaParaMaiusculo(placa);

    cout << "data da entrada(HH:MM): " << endl;
    cin >> dataEntrada;

    garagem[qtdCarros].placa = placa;
    garagem[qtdCarros].dataEntrada = dataEntrada;
    ++qtdCarros;

    gravarCarroBase(placa, dataEntrada, baseDados);
    return qtdCarros;

}
    void listarCarros(Veiculo garagem[], int qtdCarros){
    
    if (qtdCarros == 0) {
        cout << "\nGaragem vazia.\n";
    } else {
        cout << "\nListar Carros: " << endl;
        for(int i=0; i < qtdCarros; i++){
            if(garagem[i].placa.empty()) continue;
            cout << "+----------------+" << endl;
            cout << "placa:"<< garagem[i].placa << endl;
            cout << "data de entrada:" << garagem[i].dataEntrada << endl;
        }
    }
    cout << "+----------------+" << endl;
    cout << "total de carros: " << qtdCarros << endl;
}   

    int retirarVeiculo(Veiculo garagem[], int qtdCarros, string& placaBusca){
     
        int j=0;
        bool estaGaragem = false;
        for(int i=0; i < qtdCarros;i++){
            if(!estaGaragem && garagem[i].placa == placaBusca){
                estaGaragem = true;
                continue;
            }
            garagem[j++] = garagem[i];
        }
        if(estaGaragem){
            cout << "Saida do veiculo: " << placaBusca << endl;
                return j; 
        }else{
            cout << "Placa inexistente" << endl;
                return qtdCarros;
        }
        
}

void menuVeiculos(Veiculo garagem[], int tamanho, int& qtdCarros, const string& baseDados){
        int opcao;
    do{
        cabecalhoMenu(); 
        
        if (!(cin >> opcao)) {
            cout << "\nEntrada invalida. Digite um numero.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;
        } 

        switch(opcao){
            case 1:
                listarCarros(garagem, qtdCarros);
                break;
            case 2:
                qtdCarros = cadastrarCarros(garagem, qtdCarros, tamanho, baseDados);
                break;
            case 3: {
                string placa;
                cout << "\nInforme a placa do veiculo de saida: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, placa);

                placaParaMaiusculo(placa);
                int qtdCarrosNova = retirarVeiculo(garagem, qtdCarros,placa);
                
                if(qtdCarrosNova != qtdCarros){
                    qtdCarros = qtdCarrosNova;
                    salvarGaragemBase(baseDados, garagem, qtdCarros);
                }
                break;
            }
            case 4:
                 mostrarStatus(qtdCarros, tamanho); 
                break;
            case 5:
                cout << "\nEncerrando o programa!\n";
                break;
            default:
                 if (opcao != 0) {
                    cout << "\nOpcao invalida. Tente novamente!\n";
                }
        }
         if (opcao != 5) {
            cout << "\nPressione ENTER para continuar...";
            if(opcao != 2 && opcao != 3 && opcao != 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.get();
        }

    } while(opcao != 5);
}