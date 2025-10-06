#include "dominios.cartao.h"
#include <stdexcept>
#include <cctype>

using namespace std;

Cartao::Cartao(string v){
    setValor(v);
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
void Cartao::setValor(string v){
    if (v.size() != 16){
        throw::invalid_argument("Cartão inválido(deve ter 16 dígitos).");
    }
    for (char c : v){
        if (!isdigit(c)){
            throw::invalid_argument("Cartão inválido (apenas dígitos permitidos).");
        }
    }
    if (!validarLuhn(v)){
        throw::invalid_argument("Cartão inválido (falha no algoritmo de Luhn).");
    }
    valor = v;
}
string Cartao::getValor() const{
    return valor;
}
