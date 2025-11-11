/**
* @file dominios.email.cpp
* @brief Implementação dos métodos que validam objetos da classe Email.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "dominios.email.hpp"
#include <regex>
#include <string>
#include <stdexcept>

using namespace std;

Email::Email(const string& email){
    setEmail(email);
};

string Email::getEmail() const{
    return this->email;
};

void Email::setEmail(const string& email){
    validarFormato(email);
    this->email = email;

}

void Email::validarFormato(const string& email){
    regex padrao("^[a-zA-Z0-9][a-zA-Z0-9.-]{0,62}[a-zA-Z0-9]@"
                      "[a-zA-Z0-9][a-zA-Z0-9-]{0,62}[a-zA-Z0-9](\\.[a-zA-Z0-9-]+)*$"
                     );

    size_t posicaoArroba = email.find('@');
    if(posicaoArroba == string::npos){
        throw invalid_argument("O e-mail precisa  conter o caracter '@'");
    }

    if(posicaoArroba > 64 || (email.length() - posicaoArroba - 1) > 255){
        throw invalid_argument("O e-mail inserido eh invalido");
    }

    if(!regex_match(email, padrao)){
        throw invalid_argument("O e-mail esta fora do padrao.");
    }
};
