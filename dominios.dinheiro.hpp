//23/09/2025
#ifndef DOMINIOS_DINHEIRO_HPP_INCLUDED
#define DOMINIOS_DINHEIRO_HPP_INCLUDED
#include <string>

class Dinheiro{
private:
    int valorEmCentavos;
    int validarConverter(std::string valor);
    void validar(int valor);
public:
    Dinheiro(double valor);
    Dinheiro(std::string valor);
    double getValor() const;
    void setValor(double valor);
    int getValorEmCentavos() const;
};

#endif // DOMINIOS_DINHEIRO_HPP_INCLUDED
