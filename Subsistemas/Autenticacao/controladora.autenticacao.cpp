#include "autenticar.hpp"
#include "../funcoes.de.controles.hpp"
#include <iostream>
#include <string>

using namespace std;


bool validar(){
    string email, senha;
    aAutenticacao ca_autenticacao;
    msAutenticacao cs_autenticacao;

    limparTela();

    cout << "Para logar como gerente digite sua senha e email." << endl;
    cout << endl << endl << endl;
    cout << "email:   ";
    getline(cin, email);
    cout << endl;
    cout << "Senha:   ";
    getline(cin, senha);
    cout << endl << endl;

    if (ca_autenticacao.validarDados(email, senha)){
        if(cs_autenticacao.validarGerente(email, senha)){
            cout << "Autenticado com sucesso!" << endl;
            return true;
        }
    }
    return false;
}
