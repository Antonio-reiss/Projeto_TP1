/**
* @file dominios.cartao.cpp
* @brief Implementacao da classe Cartao.
*
* @author Ester Andrade Sousa - 242012109
*/
#include "dominios.cartao.hpp"
#include <stdexcept>
#include <cctype>

using namespace std;

Cartao::Cartao(string valor){
    setValor(valor);
}
bool Cartao::validarLuhn(const string &num) const{
    int soma = 0;
    bool alterar = false;

    for (int i = num.size() - 1; i >= 0; i--){
        int digito = num[i] - '0';
        if (alterar){
            digito *= 2;
            if (digito > 9) digito -= 9;
        }
        soma += digito;
        alterar = !alterar;
    }
    return (soma % 10 == 0);
}
void Cartao::setValor(string valor){
    if (valor.size() != 16){
        throw::invalid_argument("Cartão inválido(deve ter 16 dígitos).");
    }
    for (char cartao : valor){
        if (!isdigit(cartao)){
            throw::invalid_argument("Cartão inválido (apenas dígitos permitidos).");
        }
    }
    if (!validarLuhn(valor)){
        throw::invalid_argument("Cartão inválido (falha no algoritmo de Luhn).");
    }
    this->valor = valor;
}
string Cartao::getValor() const{
    return valor;
}

