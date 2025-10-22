/*
    ********************************************************************************
    *                          DESAFIO: GESTÃO DE GARAGEM                          *    
    ********************************************************************************
    * Descricao:                                                                   *
    * Esse desafio tem como principal objrtivo gerenciar o fluxo de veiculos em uma*
    * garagem. Ele permite listar veiculos estacionados, cadastrar novas placas,   *
    * registrar saidas e verificar o status das vagas.                             *
    ********************************************************************************
*/
#include <iostream>
#include <string>
#define TAM 1000

using namespace std;

#include"meusTipos.h"
#include"meusMetodos.h"

int main(){
Veiculo garagem[TAM];
    int qtdCarros = 0;
    string baseDados = "base.csv";
    
     qtdCarros = conectarBaseVeiculos(baseDados, garagem, TAM);
     menuVeiculos(garagem, TAM, qtdCarros, baseDados);

    return 1;
}