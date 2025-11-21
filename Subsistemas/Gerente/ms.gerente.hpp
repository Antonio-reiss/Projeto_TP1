/**
* @file ms.gerente.hpp
* @brief Implementação concreta do módulo de serviço do gerente.
*
* @details Esta classe herda da interface ISGerente e cotem a logica de négocio
* e orquestração para as oprações de CRUD e listagem.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef MS_GERENTE_HPP_INCLUDED
#define MS_GERENTE_HPP_INCLUDED
#include <algorithm>
#include <cctype>
#include "is.gerente.hpp"
#include "../../entidades/entidade.gerente.hpp"
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "../funcoes.de.controles.hpp"

using namespace std;

/**
* @class msGerente
* @brief Implementacao do modulo de servico para a entidade Gerente.
* @details Contem a logica de negocio e orquestracao entre a controladora
* e a camada de banco de dados.
*/
class msGerente : public isGerente{
public:
    /**
    * @brief Cria um novo registro de Gerente no sistema (persistencia).
    * @param nome Nome do Gerente, ja validado na camada de apresentacao.
    * @param email Email do Gerente, ja validado na camada de apresentacao.
    * @param ramal Ramal do Gerente, ja validado na camada de apresentacao.
    * @param senha Senha do Gerente, ja validado na camada de apresentacao.
    * @return Retorna true se a operacao de persistencia for bem-sucedida.
    */
    bool criarGerente(const string&, const string&, const int&, const string&) override;
    /**
    * @brief Exibe a lista completa de Gerentes registrados.
    */
    void listarGerentes() override;
    /**
    * @brief Atualiza os dados do Gerente.
    * @param tipoDado a opcao de dado a ser editado, o novoDado novo dado a ser registrado e e-mail de busca
    * para o banco de dados (PK).
    */
    bool editarGerente(int, string, string&) override;
    /**
    * @brief Exclui um registro de Gerente do banco de dados.
    * @param chave e-mail da conta a ser excluida, ja validado no MA e confirmado pela controladora.
    * @return Retorna true se a exclusao for bem sucedida.
    */
    bool excluirGerente(const string&) override;

};


#endif // MS_GERENTE_HPP_INCLUDED
