#include "ma.gerente.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

bool maGerente::validarConta(const string& nome, const string& email, const int& ramal, const string& senha){
    try{
        Nome nomeValido(nome);
        Email emailValido(email);
        Ramal ramalValido(ramal);
        Senha senhaValida(senha);
        return true;
    }catch(const exception& e){
        cerr << "Dados invalidos!\nErro: " << e.what() << endl;
        return false;
    }

}
