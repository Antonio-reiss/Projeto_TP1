#ifndef DOMINIOS_ENDERECO_HPP_INCLUDED
#define DOMINIOS_ENDERECO_HPP_INCLUDED

#include <string>

class Endereco{
private:
    std::string endereco;
    void validar(std::string endereco);
public:
    Endereco(std::string endereco);
    std::string getEndereco() const;
    void setEndereco(std::string nome);
};

#endif // DOMINIOS_ENDERECO_HPP_INCLUDED
