#ifndef DOMINIOS_CARTAO_H_INCLUDED
#define DOMINIOS_CARTAO_H_INCLUDED

#include <string>

using namespace std;

class Cartao{
private:
    string valor;
    bool validarLuhn (const string &num) const;
public:
    Cartao(string valor);
    void setValor(string valor);
    string getValor() const;

};

#endif // DOMINIOS_CARTAO_H_INCLUDED
