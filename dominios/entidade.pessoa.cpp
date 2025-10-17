#include "entidade.pessoa.hpp"
using namespace std;

Pessoa::Pessoa(const string& nome, const string& email):
    nome(nome),
    email(email)
{}

void Pessoa::setNome(const string& nome){
    this->nome.setNome(nome);
}
string Pessoa::getNome() const{
    return this->nome.getNome();
}

void Pessoa::setEmail(const string& email){
    this->email.setEndereco(email);
}

string Pessoa::getEmail() const{
    return this->email.getEndereco();
}
