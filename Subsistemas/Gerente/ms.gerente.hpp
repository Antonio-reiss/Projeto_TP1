/**
* @file ms.gerente.hpp
* @brief Implementação concreta do módulo de serviço do gerente.
*
* Esta classe herda da interface ISGerente e cotem a logica de négocio
* e orquestração para as oprações de CRUD e listagem.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef MS_GERENTE_HPP_INCLUDED
#define MS_GERENTE_HPP_INCLUDED
#include "is.gerente.hpp"
#include "ma.gerente.hpp"
#include "../../entidades/entidade.gerente.hpp"
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"

using namespace std;

/**
* @class msGerente
* @brief
*/
class msGerente : public isGerente<string>, public isGerente<int>{
public:
    bool criarGerente(const string&, const string&, const int&, const string&) override;
    bool lerGerente(const string&, const string&, const int&, const string&) override;
    bool editarGerente(const int&, const string&) override;
    bool editarGerente(const string&, const string&) override;
    bool excluirGerente(const string&, const string&, const int&, const string&) override;

};


#endif // MS_GERENTE_HPP_INCLUDED
