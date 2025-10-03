#include "dominios.senha.hpp"
#include <string>
#include <stdexcept>

using namespace std;

//Função para determinar o tipo de caractere da senha, entre Maiúsculas, Minúsculas, Dígitos e Caracteres Especiais.
string tipoCaractere(char caractere){
    string tipocaractere;
    if(caractere >= 'a' && caractere <= 'z') tipocaractere = "letra";
    if(caractere >= 'A' && caractere <= 'Z') tipocaractere = "letra";
    if(caractere >= '0' && caractere <= '9') tipocaractere = "digito";
    if(caractere >= '!' && caractere <= '&' || caractere == '?') tipocaractere = "caractere_especial";

    return tipocaractere;
}

bool Senha::validar_senha(string& senha){
    //Essas são flags para determinar se a senha possui cada um dos caracteres requisitados.
    short caractere_especial = 0;
    short letra_maiuscula = 0;
    short letra_minuscula = 0;
    short digito = 0;

    if (senha.size() < QTD_CARACTERES){
        throw invalid_argument("Senha muito curta, a senha deve ter 5 caracteres");
    }
    else if (senha.size() > QTD_CARACTERES){
        throw invalid_argument("Senha muito longa, a senha deve ter 5 caracteres");
    }

    for(char caractere : senha){
        if(caractere >= 'a' && caractere <= 'z') letra_minuscula = 1;
        else if(caractere >= 'A' && caractere <= 'Z') letra_maiuscula = 1;
        else if(caractere >= '0' && caractere <= '9') digito = 1;
        else if(caractere >= '!' && caractere <= '&' || caractere == '?') caractere_especial = 1;
        else throw invalid_argument("Um caractere invalido foi inserido");
    }

    if (!caractere_especial) throw invalid_argument("A senha deve conter um caractere especial");
    if (!letra_minuscula) throw invalid_argument("A senha deve conter uma letra minuscula");
    if (!letra_maiuscula) throw invalid_argument("A senha deve conter uma letra maiuscula");
    if (!digito) throw invalid_argument("A senha deve conter um digito");

    for (int caractere = 1; caractere < 6; caractere++){
        if (tipoCaractere(senha[caractere]) == tipoCaractere(senha[caractere-1])){
            throw invalid_argument("Dois termos seguidos nao podem ser do mesmo tipo");
        }
    }
    return true;
}

bool Senha::setSenha(string& senha){
    validar_senha(senha);
    this->senha = senha;
    return true;
}

Senha::Senha(string senha){
    setSenha(senha);
}

string Senha::getSenha() const{
    return this->senha;
}





