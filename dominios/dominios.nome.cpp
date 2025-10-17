#ifndef DOMINIOS_NOME_CPP_INCLUDED
#define DOMINIOS_NOME_CPP_INCLUDED
#include "dominios.nome.hpp"
#include <stdexcept>

using namespace std;

void Nome::validar(string nome){
    if(nome.length() < 5 || nome.length() > 20){
        throw invalid_argument("O nome deve ter entre 5 e 20 caracteres");
    }
    if(nome.back() == ' '){
        throw invalid_argument("O nome digitado eh invalido.");
    }

    for (size_t i = 0; i < nome.length(); ++i){
        char c = nome[i];

        if(!isalpha(c) && !isspace(c)){
                throw invalid_argument("O nome digitado eh invalido.");
            if(isspace(c)){
                    if(i + 1 < nome.length()){
                        char proximo_c = nome[i+1];

                        if(isspace(proximo_c)){
                            throw invalid_argument("O nome digitado eh invalido.");
                        }
                    }
            }
        }
    }
}

Nome::Nome(string nome){
    validar(nome);
    this->nome = nome;

}

string Nome::getNome() const{
    return this->nome;
}

void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}

#endif // DOMINIOS_NOME_CPP_INCLUDED
