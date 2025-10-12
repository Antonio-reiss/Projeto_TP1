#ifndef DOMINIOS_DATA_HPP_INCLUDED
#define DOMINIOS_DATA_HPP_INCLUDED
#include <string>

using namespace std;

class Data{
private:
    int dia;
    string mes;
    int ano;
    bool validar (int d, string m, int a) const;
public:
    Data(int d, string m, int a);
    void setValor (int d, string m, int a);
    int getDia() const;
    string getMes() const;
    int getAno() const;
    string getValor() const;
};


#endif // DOMINIOS_DATA_HPP_INCLUDED
