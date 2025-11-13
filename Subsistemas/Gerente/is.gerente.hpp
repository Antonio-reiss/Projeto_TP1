/**
* @file is.gerente.hpp
* @brief Interface Abstrata para o módulo de serviço do gerente (CRUD).
*
* Define o contrato que a camada de apresentação usará para interagir com a lógica de négocio.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef IS_GERENTE_HPP_INCLUDED
#define IS_GERENTE_HPP_INCLUDED
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class ISGerente{
    virtual bool criaGerente(const string&, const string&, const int&, const string&) = 0;
    virtual bool lerGerente(const string&, const string&, const int&, const string&) = 0;
    virtual bool editarGerente(const string&, const string&, const int&, const string&) = 0;
    virtual bool excluirGerente(const string&, const string&, const int&, const string&) = 0;
};

#endif // IS_GERENTE_HPP_INCLUDED
