#include "entidade.pessoa.hpp"

Pessoa::Pessoa(const std::string& nome, const std::string& email):
    nome(nome),
    email(email)
{}

void Pessoa::setNome(const std::string& nome){
    this->nome.setNome(nome);
}
std::string Pessoa::getNome() const{
    return this->nome.getNome();
}

void Pessoa::setEmail(const std::string& email){
    this->email.setEndereco(email);
}

std::string Pessoa::getEmail() const{
    return this->email.getEndereco();
}