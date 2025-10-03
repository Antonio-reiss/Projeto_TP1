#include "dominios.endereco.hpp"
#include <string>
#include <stdexcept>
#include <algorithm> //para usar all_of
#include <cctype> //para usar isalpha, isdigit, isspace

void Endereco::validar(std::string endereco){
    if(endereco.length() < 5 || endereco.length() > 30){
        throw std::invalid_argument("O endereco deve ter entre 5 e 30 caracteres.");
    }

    //percorre a string do primeiro indice ate o ultimo
    for(size_t i = 0; i < endereco.length(); ++i){ //o ++i incrementa na váriavel antes de usa-la
        char c = endereco[i]; //armazena o caracter atual

        //regra de caracteres permitidos
        bool isPermitido = std::isalpha(c) || std::isdigit(c) || std::isspace(c) || c == ',' || c == '.';
        if(!isPermitido){
            throw std::invalid_argument("O endereco contem caracteres invalidos!");
        }

        //verificação do penultimo e ultimo caracter
        if(i + 1 < endereco.length()){
            char proximo = endereco[i+1];

            if(std::isspace(c) && !(std::isalpha(proximo)|| std::isdigit(proximo))){
                throw std::invalid_argument("O endereco contem caracteres invalidos!");
            }
            if((c == ',' || c == '.') && (proximo == ',' || proximo == '.')){
                throw std::invalid_argument("O endereco contem caracteres invalidos!");
            }
        }
    }

    char primeiro = endereco.front(); //primeiro caracter
    char ultimo = endereco.back();  //ultimo caracter

    if(primeiro == ',' || primeiro == '.' || std::isspace(primeiro)){
        throw std::invalid_argument("O primeiro caracter precisa ser valido!");
    }
    if(ultimo == ',' || ultimo == '.' || std::isspace(ultimo)){
        throw std::invalid_argument("O ultimo caracter precisa ser valido!");
    }

}

Endereco::Endereco(std::string endereco){
    validar(endereco);
    this->endereco = endereco;
}

std::string Endereco::getEndereco() const{
    return this->endereco;
}

void Endereco::setEndereco(std::string endereco){
    validar(endereco);
    this->endereco = endereco;
}


