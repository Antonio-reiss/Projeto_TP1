#include "dominios.capacidade.hpp"
#include <stdexcept>

Capacidade::Capacidade(int valor) {
    setValor(valor);
}
void Capacidade::setValor(int valor){
    if (valor < 1 || valor > 4 ) {
        throw std::invalid_argument("Capacidade inválida(deve ser 1 a 4)");
    }
        valor = v;
    }
int Capacidade::getValor() const{
    return valor;
}


