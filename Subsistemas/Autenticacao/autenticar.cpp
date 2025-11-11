#include "autenticar.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return;
}

bool validar(){
    string email, senha;
    aAutenticacao autenticacao;

    limparTela();

    cout << "Para logar como gerente digite sua senha e email." << endl;
    cout << endl << endl << endl;
    cout << "email:   ";
    getline(cin, email);
    cout << endl;
    cout << "Senha:   ";
    getline(cin, senha);
    cout << endl << endl;

    if (autenticacao.validarDados(email, senha)){
        cout << "Autenticado com sucesso!" << endl << endl;
    }
}
