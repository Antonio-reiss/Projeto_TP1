//Dominio Email - 23/09/2025
#include "dominios.email.hpp"
#include <regex>

Email::Email(const std::string& endereco){
    if(!setEndereco(endereco)){
        throw std::invalid_argument("Endereco de email invalido");
    }
    this->endereco = endereco;
};

std::string Email::getEndereco() const{
    return this->endereco;
};

bool Email::setEndereco(const std::string& endereco){
    if(validarFormato(endereco)){
        this->endereco = endereco;
        return true;
    }
    return false;
}

bool Email::validarFormato(const std::string& email){
    std::regex padrao("^[a-zA-Z0-9][a-zA-Z0-9.-]{0,62}[a-zA-Z0-9]@"
                      "[a-zA-Z0-9][a-zA-Z0-9-]{0,62}[a-zA-Z0-9](\\.[a-zA-Z0-9-]+)*$"
                     );

    size_t posicaoArroba = email.find('@');
    if(posicaoArroba == std::string::npos){
        return false; //não há '@'
    }

    if(posicaoArroba > 64 || (email.length() - posicaoArroba - 1) > 255){
        return false;
    }

    return std::regex_match(email, padrao);
};
