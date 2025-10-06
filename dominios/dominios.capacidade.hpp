#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include<stdexcept>

using namespace std;

class Capacidade {
private:
    int valor;
public:
    Capacidade (int v);
    void setValor (int v);
    int getValor () const;

};


#endif // DOMINIOS_HPP_INCLUDED
