#include "controladora.autenticacao.hpp"
#include "../funcoes.de.controles.hpp"
#include <iostream>
#include <string>

using namespace std;


bool validar(){
    string email, senha;
    maAutenticacao ca_autenticacao;
    msAutenticacao cs_autenticacao;

    while (1){
        limparTela();

        cout << "\n==================================" << endl;
        cout << "           TELA DE LOGIN  " << endl;
        cout <<   "==================================" << endl;
        cout << "\tDigite senha e email." << endl;
        cout << endl << endl;
        cout << "email:\t";
        getline(cin, email);
        if(email == "0")
            return false;
        cout << endl;
        cout << "Senha:\t";
        getline(cin, senha);
        cout << endl << endl;

        string validado;
        if (ca_autenticacao.validarDados(email, senha)){
            validado = cs_autenticacao.validarGerente(email, senha);
        }

        if (validado == "Usuario nao encontrado."){
            cout << validado << endl;
            esperar(4);
            break;
        }
        if (validado == "Usuario validado!"){
            cout << validado << endl;
            esperar(2);
            return true;
        }
        if (validado == "Senha incorreta!!"){
            cout << validado << endl;
            esperar(3);
        }
    }
    return false;
}
