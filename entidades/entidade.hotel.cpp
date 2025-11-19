/**
 * @file entidade.hotel.cpp
 * @brief Implementação da classe Hotel.
 * @author Ester Andrade Sousa - 242012109
 */
#include "entidade.hotel.hpp"

Hotel::Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo) : nome(nome), endereco(endereco), telefone(telefone), codigo(codigo){}

void Hotel::setNome(const Nome& nome){
    this->nome = nome;
}
void Hotel::setEndereco(const Endereco& endereco){
    this->endereco = endereco;
}
void Hotel::setTelefone(const Telefone& telefone){
    this->telefone = telefone;
}
void Hotel::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Nome Hotel::getNome() const{
    return nome;
}
Endereco Hotel::getEndereco() const{
    return endereco;
}
Telefone Hotel::getTelefone() const{
    return telefone;
}
Codigo Hotel::getCodigo() const{
    return codigo;
}
