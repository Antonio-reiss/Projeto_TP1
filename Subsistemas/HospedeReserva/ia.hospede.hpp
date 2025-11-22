/**
 * @file ia_hospede.hpp
 * @brief Interface que define operacoes para manipulacao de hospedes no sistema de gestao hoteleira.
 *
 * Esta interface e utilizada para validar operacoes de criar, editar e excluir hospedes
 * dentro do sistema. As classes que implementam esta interface devem garantir que as
 * regras de negocio especificas sejam respeitadas.
 *
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef IA_HOSPEDE_HPP_INCLUDED
#define IA_HOSPEDE_HPP_INCLUDED

#include <string>

using namespace std;

/**
 * @class IAHospede
 * @brief Interface responsavel por definir metodos de validacao de hospedes.
 *
 * Classes que implementam esta interface devem tratar a validacao dos dados
 * para operacoes de criacao, edicao e exclusao de hospedes.
 */
class IAHospede {
public:
    /**
     * @brief Valida os dados de criacao de um hospede.
     * @param nome String com o nome do hospede.
     * @param endereco String com o endereco completo do hospede.
     * @param cartao String com o numero do cartao de credito do hospede.
     * @param email String com o email pessoal do hospede.
     * @return true se todos os dados forem validos, false caso contrario.
     */
    virtual bool validarCriar(string& nome, string& endereco, string& cartao, string& email) = 0;

    /**
     * @brief Valida os dados de edicao de um hospede.
     * @param nome String com o nome do hospede (nao pode ser alterado se for chave primaria).
     * @param endereco String com o novo endereco.
     * @param email String com o novo email.
     * @return true se os dados forem validos, false caso contrario.
     */
    virtual bool validarEditar(string& nome, string& endereco, string& email) = 0;

    /**
     * @brief Valida a exclusao de um hospede.
     * @param nome String com o nome do hospede a ser excluido (chave primaria).
     * @return true se a exclusao for permitida, false caso contrario.
     */
    virtual bool validarExcluir(string& nome) = 0;
};

#endif // IA_HOSPEDE_HPP_INCLUDED
