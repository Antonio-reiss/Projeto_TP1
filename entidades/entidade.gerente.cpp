#include "entidade.gerente.hpp"

using namespace std;

Gerente::Gerente(string& nome, string& email, int& ramal, string& senha) : Pessoa(nome, email), ramal(ramal), senha(senha){};

void Gerente::setRamal(int& ramal){
    this->ramal.setRamal(ramal);
}

void Gerente::setSenha(string& senhaNova){
    this->senha.setSenha(senhaNova);
}

void Gerente::setNome(string& nomeNovo){
    Pessoa::setNome(nomeNovo);
}

void Gerente::setEmail(string& emailNovo){
    Pessoa::setEmail(emailNovo);
}

int Gerente::getRamal() const {
    return this->ramal.getRamal();
}

string Gerente::getGerenteNome() const{
    return this->getNome();
}

string Gerente::getGerenteEmail() const{
    return this->getEmail();
    }

string Gerente::getSenha() const{
    return this->senha.getSenha();
}
