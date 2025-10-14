#ifndef DOMINIOS_CODIGO_HPP_INCLUDED
#define DOMINIOS_CODIGO_HPP_INCLUDED
#include<string>
using namespace std;

class Codigo{
private:
    string valor;
public:
    Codigo(string v);
    void setValor (string v);
    string getValor() const;
};

#endif // DOMINIOS_CODIGO_HPP_INCLUDED
