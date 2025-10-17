#include "dominios.endereco.hpp"
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

using namespace std;

void Endereco::validar(string endereco){
    if(endereco.length() < 5 || endereco.length() > 30){
        throw invalid_argument("O endereco deve ter entre 5 e 30 caracteres.");
    }

    for(size_t i = 0; i < endereco.length(); ++i){
        char c = endereco[i];

        bool isPermitido = isalpha(c) || isdigit(c) || isspace(c) || c == ',' || c == '.';
        if(!isPermitido){
            throw invalid_argument("O endereco contem caracteres invalidos!");
        }

        if(i + 1 < endereco.length()){
            char proximo = endereco[i+1];

            if(isspace(c) && !(isalpha(proximo)|| isdigit(proximo))){
                throw invalid_argument("O endereco contem caracteres invalidos!");
            }
            if((c == ',' || c == '.') && (proximo == ',' || proximo == '.')){
                throw invalid_argument("O endereco contem caracteres invalidos!");
            }
        }
    }

    char primeiro = endereco.front();
    char ultimo = endereco.back();

    if(primeiro == ',' || primeiro == '.' || isspace(primeiro)){
        throw invalid_argument("O primeiro caracter precisa ser valido!");
    }
    if(ultimo == ',' || ultimo == '.' || isspace(ultimo)){
        throw invalid_argument("O ultimo caracter precisa ser valido!");
    }

}

Endereco::Endereco(string endereco){
    validar(endereco);
    this->endereco = endereco;
}

string Endereco::getEndereco() const{
    return this->endereco;
}

void Endereco::setEndereco(string endereco){
    validar(endereco);
    this->endereco = endereco;
}


