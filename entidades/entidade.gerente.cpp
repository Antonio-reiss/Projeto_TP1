#include "entidade.gerente.hpp"

using namespace std;

Gerente::Gerente(const string& nome, const string& email, const int& ramal, const string& senha) : Pessoa(nome, email), ramal(ramal), senha(senha){};

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

//string Gerente::getNome() const{
//    return this->nome.getNome();
//}

//string Gerente::getEmail() const{
//    return this->email.getEmail();
//}

string Gerente::getSenha() const{
    return this->senha.getSenha();
}
