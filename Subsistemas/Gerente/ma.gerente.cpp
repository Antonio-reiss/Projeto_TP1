#include "ma.gerente.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

bool maGerente::validarConta(const string& nome, const string& email, const float& ramal, const string& senha){
    try{
        Nome nomeValido(nome);
        Email emailValido(email);
        Ramal ramalValido(ramal);
        Senha senhaValida(senha);

        cout << "Dados cadastrados com sucesso!" << endl;
        return true;
    }catch(const exception& e){
        cerr << "Dados invalidos!\nOcorreu um erro: " << e.what() << endl;
        return false;
    }

}
