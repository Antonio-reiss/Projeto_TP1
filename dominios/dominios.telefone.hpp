#ifndef DOMINIOS_TELEFONE_HPP_INCLUDED
#define DOMINIOS_TELEFONE_HPP_INCLUDED
#include <string>
using namespace std;

class Telefone{
private:
    string telefone;
    bool validar_telefone(string&);
public:
    Telefone(string);
    bool setTelefone(string&);
    string getTelefone() const;

};

#endif // DOMINIOS_TELEFONE_HPP_INCLUDED
