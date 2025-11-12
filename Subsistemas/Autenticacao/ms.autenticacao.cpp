#include "ms.autenticacao.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

void buscarGerentes(vector<Gerente>& gerentes){
    string nome, email, senha;
    int ramal;

    nome = "Joselino", email = "jose@gmail.com", ramal = 22, senha = "1!a!A";
    gerentes.push_back(Gerente(nome, email, ramal, senha));
    nome = "Ana Clara", email = "ana@gmail.com", ramal = 23, senha = "a2A!3";
    gerentes.push_back(Gerente(nome, email, ramal, senha));
    nome = "Roberto", email = "roberto@gmail.com", ramal = 1, senha = "L1l!1";
    gerentes.push_back(Gerente(nome, email, ramal, senha));

    return;
}

bool msAutenticacao::validarGerente(string& email, string& senha){
    bool emailCerto = false;
    int i;
    vector<Gerente> gerentes;
    buscarGerentes(gerentes);

    for(i = 0; i < gerentes.size(); i++){
        if(gerentes[i].getGerenteEmail() == email){
            emailCerto = true;
            break;
        }
    }
    if(emailCerto){
        if(gerentes[i].getSenha() == senha){
            return true;
        }
        else {
            cout << "Senha incorreta" << endl;
        }
    }
    cout << "Email informado nao registrado" << endl;
    return false;
}
