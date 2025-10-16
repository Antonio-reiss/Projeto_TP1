#ifndef DOMINIOS_DATA_HPP_INCLUDED
#define DOMINIOS_DATA_HPP_INCLUDED
#include <string>

using namespace std;

class Data{
private:
    int dia;
    string mes;
    int ano;
    bool validar (int dia, string mes, int ano) const;
public:
    Data(int dia, string mes, int ano);
    void setValor (int dia, string mes, int ano);
    int getDia() const;
    string getMes() const;
    int getAno() const;
    string getValor() const;
};


#endif // DOMINIOS_DATA_HPP_INCLUDED
