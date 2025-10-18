#include "entidade.hospede.h"

Hospede::Hospede(const std::string& nome, const std::string& email, const std::string& endereco, const std::string& cartao) : Pessoa(nome,email), endereco(endereco),cartao(cartao){}

void Hospede::setEndereco(const std::string& endereco){
    this->endereco.setEndereco(endereco);
}
std::string Hospede::getEndereco() const {
    return this->endereco.getEndereco();
}
void Hospede::setCartao(const std::string& cartao) {
    this->cartao.setValor(cartao);
}

std::string Hospede::getCartao() const {
    return this->cartao.getValor();
}
