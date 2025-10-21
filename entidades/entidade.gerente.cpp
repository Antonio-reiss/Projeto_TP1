#include "entidade.gerente.hpp"

using namespace std;

Gerente::Gerente(const string& nome, const string& email, const int& ramal, const string& senha) : Pessoa(nome, email), ramal(ramal), senha(senha){};

void Gerente::setRamal(int& ramal){
    this->ramal.setRamal(ramal);
}

void Gerente::setSenha(string& senhaNova){
    this->senha.setSenha(&senhaNova);
}

void Gerente::setNome(string& nomeNovo){
    Pessoa::setNome(const &nomeNovo);
}

void Gerente::setEmail(string& emailNovo){
    Pessoa::setEmail(const &emailNovo);
}
