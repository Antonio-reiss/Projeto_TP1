#ifndef DOMINIOS_CODIGO_HPP_INCLUDED
#define DOMINIOS_CODIGO_HPP_INCLUDED
#include<string>
using namespace std;

class Codigo{
private:
    string valor;
public:
    Codigo(string valor);
    void setValor (string valor);
    string getValor() const;

};

#endif // DOMINIOS_CODIGO_HPP_INCLUDED
