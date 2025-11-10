#include "dominios.numero.hpp"
#include <stdexcept>

using namespace std;

bool Numero::validar_numero(int numero){
    if (numero < MIN_VALOR || numero > MAX_VALOR){
        throw invalid_argument("O valor deve um número de 001 a 999");
    }
    return true;
}

void Numero::setNumero(int numero){
    validar_numero(numero);
    this->numero = numero;
}

Numero::Numero(int numero){
    setNumero(numero);
}

int Numero::getNumero() const{
    return this->numero;
}
