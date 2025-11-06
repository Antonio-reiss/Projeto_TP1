#include "ma.autenticacao.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

bool aAutenticacao::validarDados(string& email, string& senha){
    try {
        Email emailValido(email);
    }
    catch(exception){
        cout << "Email nao segue o requisitado pelo sistema" << endl;
        return false;
    }
    try {
        Senha senhaValida(senha);
    }
    catch (const exception& error) {
        cout << error.what() << endl;
        return false;
    }
    return true;
}
