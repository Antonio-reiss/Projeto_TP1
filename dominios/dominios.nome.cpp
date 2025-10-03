#ifndef DOMINIOS_NOME_CPP_INCLUDED
#define DOMINIOS_NOME_CPP_INCLUDED
#include "dominios.nome.hpp"
#include <stdexcept>

void Nome::validar(std::string nome){
    if(nome.length() < 5 || nome.length() > 20){
        throw std::invalid_argument("O nome deve ter entre 5 e 20 caracteres");
    }
    if(nome.back() == ' '){
        throw std::invalid_argument("O nome digitado eh invalido.");
    }

    for (size_t i = 0; i < nome.length(); ++i){
        char c = nome[i];

        if(!std::isalpha(c) && !std::isspace(c)){
                throw std::invalid_argument("O nome digitado eh invalido.");
            if(std::isspace(c)){
                    if(i + 1 < nome.length()){
                        char proximo_c = nome[i+1];

                        if(std::isspace(proximo_c)){
                            throw std::invalid_argument("O nome digitado eh invalido.");
                        }
                    }
            }
        }
    }
}

Nome::Nome(std::string nome){
    validar(nome);
    this->nome = nome;

}

std::string Nome::getNome() const{
    return this->nome;
}

void Nome::setNome(std::string nome){
    validar(nome);
    this->nome = nome;
}

#endif // DOMINIOS_NOME_CPP_INCLUDED
