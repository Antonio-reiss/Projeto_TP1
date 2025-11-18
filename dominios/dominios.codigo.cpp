/**
* @file dominios.codigo.cpp
* @brief Implementacao da classe Codigo.
*
* @author Ester Andrade Sousa - 242012109
*/
#include "dominios.codigo.hpp"
#include <stdexcept>
#include <cctype>

Codigo::Codigo(string valor){
    setValor(valor);
}
void Codigo::setValor(string valor){
    if (valor.size() != 10){
        throw::invalid_argument("Codigo invalido (deve ter exatamente 10 caracteres).");
    }
    for (char codigo : valor){
        if (!islower(codigo) && !isdigit(codigo)){
            throw::invalid_argument("Codigo invalido (apenas letras minusculas e digitos permitidos).");
            }
    }
         this->valor = valor;
    }
string Codigo::getValor() const{
    return this->valor;
}

