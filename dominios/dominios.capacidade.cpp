/**
* @file dominios.capacidade.cpp
* @brief Implementacao dos metodos da classe Capacidade.
*
* @author Ester Andrade Sousa - 242012109
*/
#include "dominios.capacidade.hpp"
#include <stdexcept>

Capacidade::Capacidade(int valor) {
    setValor(valor);
}
void Capacidade::setValor(int valor){
    if (valor < 1 || valor > 4 ) {
        throw std::invalid_argument("Capacidade inválida(deve ser 1 a 4)");
    }
        this->valor = valor;
    }
int Capacidade::getValor() const{
    return valor;
}


