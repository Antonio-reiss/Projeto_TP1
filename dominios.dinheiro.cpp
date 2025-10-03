#include "dominios.dinheiro.hpp"
#include <stdexcept>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

int Dinheiro::validarConverter(std::string valor){
    for(char c : valor){
        if(!std::isdigit(c) && c != '.' && c !=','){
            throw std::invalid_argument("Formato invalido! Digite apenas numeros.");
        }
    }

    std::string temp = valor;

    temp.erase(std::remove(temp.begin(), temp.end(), '.'), temp.end());

    std::replace(temp.begin(), temp.end(), ',', '.');

    double valor_decimal;

    try{
        valor_decimal = std::stod(temp);
    }catch(const std::invalid_argument&){
        throw std::invalid_argument("Fomato invalido!");
    }catch(const std::out_of_range&){
        throw std::invalid_argument("Valor invalido!");
    }

    if(valor_decimal < 0.01 || valor_decimal > 1000000.00){
        throw std::invalid_argument("O valor deve ser entre 0,01 e 1.000.000,00");
    }

    return static_cast<int>(std::round(valor_decimal * 100.0));
}

void Dinheiro::validar(int valor){
    if(valor < 1 || valor > 100000000){
        throw std::invalid_argument("O valor deve estar no intervalo 0,01 e 1.000.000,00");
    }
}

Dinheiro::Dinheiro(std::string valor){
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
    int valorEmCentavosConvetido = static_cast<int>(std::round(valor * 100.0));
    validar(valorEmCentavosConvetido);
    this->valorEmCentavos = valorEmCentavosConvetido;
}

int Dinheiro::getValorEmCentavos() const{
    return valorEmCentavos;
}
