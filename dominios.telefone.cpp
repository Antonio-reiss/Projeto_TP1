#include "dominios.telefone.hpp"
#include <stdexcept>
#include <string>

using namespace std;

bool Telefone::validar_telefone(string &telefone){
    for (char digito : telefone){
        if (digito < '0' || digito > '9'){
            throw invalid_argument("O telefone deve ser composto apenas por digitos de 0-9");
        }
    }
    if (telefone.size() < 13){
        throw invalid_argument("O telefone esta incompleto");
    }
    else if (telefone.size() > 13){
        throw invalid_argument("O telefone tem digitos a mais");
    }
    return true;
}

bool Telefone::setTelefone(string &telefone){
    validar_telefone(telefone);
    this->telefone = '+' + telefone;
    return true;
}

Telefone::Telefone(string telefone){
    setTelefone(telefone);
}

string Telefone::getTelefone() const{
    return this->telefone;
}
