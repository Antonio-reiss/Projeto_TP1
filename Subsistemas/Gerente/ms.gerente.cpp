/**
* @file ms.gerente.cpp
* @brief Implementacao da logica de servico para o gerente.
*/
#include "ms.gerente.hpp"
#include "ma.gerente.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

#include "../BancoDados/bancoDeDados.hpp"

using namespace std;

bool msGerente::criarGerente(const string& nome, const string& email, const int& ramal, const string& senha){
    bancoDeDados bd;
    Gerente gerente(nome, email, ramal, senha);
    bd.criarGerente(gerente);
    cout << "Gerente criado com sucesso!" << endl;
    esperar(5);
    return true;
}

void msGerente::listarGerentes(){
    limparTela();
    cout << "\n================================" <<  endl;
    cout << "       LISTA DE GERENTES    " << endl;
    cout << "================================" <<  endl;
    bancoDeDados bd;
    bd.listarTodos("gerente");
    cout << "\n================================" <<  endl;
    string opcao;
    do{
        cout << "-> Digite 's' para sair: ";
        getline(cin, opcao);
        std::transform(opcao.begin(), opcao.end(), opcao.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if(opcao == "s"){
            return;
        }
    }while(true);
}

bool msGerente::editarGerente(int tipoDado, string novoDado, string& email){
    //Gerente& gerente, string& emailReferencia
    bancoDeDados bd;
    Gerente edicaoGerente("Ellen", email, 04, "E5&0l");
    bd.editarGerente(edicaoGerente, email);
    return true;
}

bool msGerente::excluirGerente(const string& chave){
    //passar para o banco de dados "gerente", tipoChave, chave
    bancoDeDados bd;
    try{
         bd.apagarUm("gerente", "email", chave);
        cout << "Conta sendo excluida..." << endl;
        esperar(2);
        cout << "Conta excluida com sucesso!" << endl;
        esperar(2);
        return true;
    }catch(const invalid_argument& erro){
        cout << erro.what() << endl;
    }

}

