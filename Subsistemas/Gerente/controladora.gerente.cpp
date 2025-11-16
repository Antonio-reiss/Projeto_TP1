/**
* @file controladora.gerente.cpp
* @brief Impelementação das funções que administram a entrada e saída de dados do subsistema gerente.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "controladora.gerente.hpp"
#include <iostream>
#include <limits>

using namespace std;

void opcoesGerente(){
    //ler, editar e excluir - gerente n pode criar gerente
}

bool validarCriarGerente(){
    string nome, email, senha;
    int ramal;
    maGerente gerente;
    msGerente novoGerente;

    do{
        limparTela();

        cout << "\n================================" << endl;
        cout << "      Criar conta Gerente         " << endl;
        cout << "================================" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "E-mail: ";
        getline(cin, email);
        cout << "Ramal: ";
        cin >> ramal;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Senha: ";
        getline(cin, senha);
        cout << endl << endl;

        if(gerente.validarConta(nome, email, ramal, senha)){
            novoGerente.criarGerente(nome, email, ramal, senha);
            return true;
        }

    }while(true);

}

