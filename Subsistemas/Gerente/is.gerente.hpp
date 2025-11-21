/**
* @file is.gerente.hpp
* @brief Interface Abstrata para o modulo de servico do gerente (CRUD).
*
* Define o contrato que a camada de apresentacao usara para interagir com a logica de negocio.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef IS_GERENTE_HPP_INCLUDED
#define IS_GERENTE_HPP_INCLUDED
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

/**
* @class isGerente
* @brief classe abstrata que define o CRUD do gerente.
*/
class isGerente{
public:
    /**

    */
    virtual bool criarGerente(const string&, const string&, const int&, const string&) = 0;
    virtual void listarGerentes() = 0;
    virtual bool editarGerente(int, string, string&) = 0;
    virtual bool excluirGerente(const string&) = 0;
};

#endif // IS_GERENTE_HPP_INCLUDED
