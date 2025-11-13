/**
* @file controladora.gerente.cpp
* @brief Impelementação das funções que administram a entrada e saída de dados do subsistema gerente.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "controladora.gerente.hpp"
#include "../Autenticacao/autenticar.hpp"
#include "../IU/iu.hpp"
#include <iostream>
#include <limits>

using namespace std;

bool validarGerente(){
    string nome, email, senha;
    int ramal;
    maGerente gerente;

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
        cout << "Conta gerente criada com sucesso!" << endl;
    }
    return true;
}

