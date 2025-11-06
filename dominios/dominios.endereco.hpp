#ifndef DOMINIOS_ENDERECO_HPP_INCLUDED
#define DOMINIOS_ENDERECO_HPP_INCLUDED
#include <string>
using namespace std;

class Endereco{
private:
    string endereco;
    bool validar(string endereco);
public:
    Endereco(string endereco);
    string getEndereco() const;
    void setEndereco(string nome);
};

#endif // DOMINIOS_ENDERECO_HPP_INCLUDED
