//Dominio Email - 23/09/2025
#include "dominios.email.hpp"
#include <regex>
#include <string>

using namespace std;

Email::Email(const string& endereco){
    if(!setEndereco(endereco)){
        throw invalid_argument("Endereco de email invalido");
    }
    this->endereco = endereco;
};

string Email::getEndereco() const{
    return this->endereco;
};

bool Email::setEndereco(const string& endereco){
    if(validarFormato(endereco)){
        this->endereco = endereco;
        return true;
    }
    return false;
}

bool Email::validarFormato(const string& email){
    regex padrao("^[a-zA-Z0-9][a-zA-Z0-9.-]{0,62}[a-zA-Z0-9]@"
                      "[a-zA-Z0-9][a-zA-Z0-9-]{0,62}[a-zA-Z0-9](\\.[a-zA-Z0-9-]+)*$"
                     );

    size_t posicaoArroba = email.find('@');
    if(posicaoArroba == string::npos){
        return false;
    }

    if(posicaoArroba > 64 || (email.length() - posicaoArroba - 1) > 255){
        return false;
    }

    return regex_match(email, padrao);
};
