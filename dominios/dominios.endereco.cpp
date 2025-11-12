/**
* @file dominios.endereco.cpp
* @brief Implementação dos métodos de validação da classe Endereco.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
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
            throw invalid_argument("O endereco possui caracteres invalidos");
        }

        if(i + 1 < endereco.length()){
            char proximo = endereco[i+1];

            if(isspace(c) && !(isalpha(proximo)|| isdigit(proximo))){
                throw invalid_argument("O endereco nao pode conter espacos seguidos");
            }
            if((c == ',' || c == '.') && (proximo == ',' || proximo == '.')){
                throw invalid_argument("O endereco nao pode ter espacos seguidos.");
            }
        }
    }

    char primeiro = endereco.front();
    char ultimo = endereco.back();

    if(primeiro == ',' || primeiro == '.' || isspace(primeiro)){
        throw invalid_argument("O endereco nao pode comecar com ponto, virgula ou espaco.");
    }
    if(ultimo == ',' || ultimo == '.' || isspace(ultimo)){
        throw invalid_argument("O endereco nao pode terminar com ponto, virgula ou espaco.");
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


