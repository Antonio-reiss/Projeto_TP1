#include "dominios.dinheiro.hpp"
#include <stdexcept>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int Dinheiro::validarConverter(string valor){
    for(char c : valor){
        if(!isdigit(c) && c != '.' && c !=','){
            throw invalid_argument("Formato invalido! Digite apenas numeros.");
        }
    }

    string temp = valor;

    temp.erase(remove(temp.begin(), temp.end(), '.'), temp.end());

    replace(temp.begin(), temp.end(), ',', '.');

    double valor_decimal;

    try{
        valor_decimal = stod(temp);
    }catch(const invalid_argument&){
        throw invalid_argument("Fomato invalido!");
    }catch(const out_of_range&){
        throw invalid_argument("Valor invalido!");
    }

    if(valor_decimal < 0.01 || valor_decimal > 1000000.00){
        throw invalid_argument("O valor deve ser entre 0,01 e 1.000.000,00");
    }

    return static_cast<int>(round(valor_decimal * 100.0));
}

void Dinheiro::validar(int valor){
    if(valor < 1 || valor > 100000000){
        throw invalid_argument("O valor deve estar no intervalo 0,01 e 1.000.000,00");
    }
}

Dinheiro::Dinheiro(string valor){
    this->valorEmCentavos = validarConverter(valor);
}

Dinheiro::Dinheiro(double valor){
    int valorEmCentavosConvertido = static_cast<int>(valor * 100);
    validar(valorEmCentavosConvertido);
    this->valorEmCentavos = valorEmCentavosConvertido;
}

double Dinheiro::getValor() const{
    return static_cast<double>(this->valorEmCentavos) / 100.0;
}

void Dinheiro::setValor(double valor){
    int valorEmCentavosConvetido = static_cast<int>(round(valor * 100.0));
    validar(valorEmCentavosConvetido);
    this->valorEmCentavos = valorEmCentavosConvetido;
}

int Dinheiro::getValorEmCentavos() const{
    return valorEmCentavos;
}
