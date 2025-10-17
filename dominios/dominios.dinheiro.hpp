//23/09/2025
#ifndef DOMINIOS_DINHEIRO_HPP_INCLUDED
#define DOMINIOS_DINHEIRO_HPP_INCLUDED
#include <string>

using namespace std;

class Dinheiro{
private:
    int valorEmCentavos;
    int validarConverter(string valor);
    void validar(int valor);
public:
    Dinheiro(double valor);
    Dinheiro(string valor);
    double getValor() const;
    void setValor(double valor);
    int getValorEmCentavos() const;
};

#endif // DOMINIOS_DINHEIRO_HPP_INCLUDED
