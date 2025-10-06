#include "dominios.codigo.hpp"
#include <stdexcept>
#include <cctype>

Codigo::Codigo(string v){
    setValor(v);
}
void Codigo::setValor(string v){
    if (v.size() != 10){
        throw::invalid_argument("Codigo invalido (deve ter exatamente 10 caracteres).");
    }
    for (char c : v){
        if (!islower(c) && !isdigit(c)){
            throw::invalid_argument("Codigo invalido (apenas letras minusculas e digitos permitidos).");
            }
    }
         valor = v;
    }
string Codigo::getValor() const{
    return valor;
}
