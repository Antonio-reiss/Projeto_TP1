/**
* @file dominios.telefone.cpp
* @brief Implementacao dos metodos, que representa e valida um numero de telefone da classe Telefone.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#include "dominios.telefone.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

bool Telefone::validar_telefone(string &telefone){
    for (char digito = 0; digito < telefone.size(); digito++){
        if (telefone[digito] < '0' || digito > '9'){
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

void Telefone::setTelefone(string& telefone){
    validar_telefone(telefone);
    this->telefone = '+' + telefone;
}

Telefone::Telefone(string telefone){
    setTelefone(telefone);
}

string Telefone::getTelefone() const{
    return this->telefone;
}
