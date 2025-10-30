#ifndef DOMINIOS_NOME_CPP_INCLUDED
#define DOMINIOS_NOME_CPP_INCLUDED
#include "dominios.nome.hpp"
#include <stdexcept>

using namespace std;

bool Nome::validar(string nome){
    if(nome.length() < 5 || nome.length() > 20){
        return false;
    }
    if(nome.back() == ' '){
        return false;
    }

    for (size_t i = 0; i < nome.length(); ++i){
        char c = nome[i];

        if(!isalpha(c) && !isspace(c)){
            return false;
        }
        if(isspace(c)&& i + 1 < nome.length()){
            char proximo_c = nome[i+1];
            if(isspace(proximo_c)){
                return false;
            }
        }
    }
    return true;
}

Nome::Nome(string nome){
    if(!validar(nome)){
        throw invalid_argument("O nome inserido eh invalido!");
    }
    this->nome = nome;

}

string Nome::getNome() const{
    return this->nome;
}

void Nome::setNome(string nome){
    if(validar(nome)){
        throw invalid_argument("O nome inserido eh invalido!");
    }
    this->nome = nome;
}

#endif // DOMINIOS_NOME_CPP_INCLUDED
