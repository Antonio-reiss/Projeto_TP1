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

using namespace std;

class msGerente : public isGerente{
public:
    bool criarGerente(const string& nome, const string& email, const int& ramal, const string& senha) override;
    bool lerGerente(const string& nome, const string& email, const int& ramal, const string& senha) override;
    bool editarGerente(const string& nome, const string& email, const int& ramal, const string& senha) override;
    bool excluirGerente(const string& nome, const string& email, const int& ramal, const string& senha) override;

};


#endif // MS_GERENTE_HPP_INCLUDED
