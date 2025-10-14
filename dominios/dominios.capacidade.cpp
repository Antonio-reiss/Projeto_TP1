#include "dominios.capacidade.hpp"
#include <stdexcept>

Capacidade::Capacidade(int v) {
    setValor(v);
}
void Capacidade::setValor(int v){
    if (v < 1 || v > 4 ) {
        throw std::invalid_argument("Capacidade inválida(deve ser 1 a 4)");
    }
        valor = v;
    }
int Capacidade::getValor() const{
    return valor;
}
