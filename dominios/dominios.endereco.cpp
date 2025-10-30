#include "dominios.endereco.hpp"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

using namespace std;

bool Endereco::validar(string endereco){
    if(endereco.length() < 5 || endereco.length() > 30){
        return false;
    }

    for(size_t i = 0; i < endereco.length(); ++i){
        char c = endereco[i];

        bool isPermitido = isalpha(c) || isdigit(c) || isspace(c) || c == ',' || c == '.';
        if(!isPermitido){
            return false;
        }

        if(i + 1 < endereco.length()){
            char proximo = endereco[i+1];

            if(isspace(c) && !(isalpha(proximo)|| isdigit(proximo))){
                return false;
            }
            if((c == ',' || c == '.') && (proximo == ',' || proximo == '.')){
                return false;
            }
        }
    }

    char primeiro = endereco.front();
    char ultimo = endereco.back();

    if(primeiro == ',' || primeiro == '.' || isspace(primeiro)){
        return false;
    }
    if(ultimo == ',' || ultimo == '.' || isspace(ultimo)){
        return false;
    }

    return true;

}

Endereco::Endereco(string endereco){
    if(!validar(endereco)){
        throw invalid_argument("O endereco inserido eh invalido");
    }
    this->endereco = endereco;
}

string Endereco::getEndereco() const{
    return this->endereco;
}

void Endereco::setEndereco(string endereco){
    if(!validar(endereco)){
        throw invalid_argument("O endereco inserido eh invalido");
    }
    this->endereco = endereco;
}


