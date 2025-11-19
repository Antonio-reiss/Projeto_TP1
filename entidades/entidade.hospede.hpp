/**
 * @file entidade.hospede.hpp
 * @brief Declaração da classe Hospede, que representa um usuário do sistema de hospedagem.
 *
 * Esta classe estende Pessoa e adiciona informações específicas de hóspedes,
 * como endereço e cartão de crédito, utilizando classes de domínio para garantir
 * validações consistentes e seguras.
 *
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef ENTIDADE_HOSPEDE_HPP_INCLUDED
#define ENTIDADE_HOSPEDE_HPP_INCLUDED

#include "entidade.pessoa.hpp"
#include "../dominios/dominios.endereco.hpp"
#include "../dominios/dominios.cartao.hpp"

/**
 * @class Hospede
 * @brief Representa um hóspede, estendendo os dados básicos de Pessoa.
 *
 * A classe Hospede armazena e valida informações adicionais, como endereço
 * e cartão, utilizando os domínios correspondentes. Esta entidade é utilizada
 * para operações relacionadas a reservas e gerenciamento de usuários.
 */

class Hospede : public Pessoa{
private:
    Endereco endereco;
    Cartao cartao;
public:
/**
     * @brief Constrói um objeto Hospede com todas as informações essenciais.
     *
     * @param nome Nome completo do hóspede.
     * @param email Email cadastrado do hóspede.
     * @param endereco Endereço em formato válido segundo o domínio Endereco.
     * @param cartao Número do cartão em formato válido segundo o domínio Cartao.
     */
    Hospede(const std::string& nome,
            const std::string& email,
            const std::string& endereco,
            const std::string& cartao);
 /**
     * @brief Define um novo endereço para o hóspede.
     *
     * @param endereco String contendo o endereço a ser validado.
     */
    void setEndereco(const std::string& endereco);
 /**
     * @brief Retorna o endereço atual do hóspede.
     *
     * @return Endereço em formato string.
     */
    std::string getEndereco() const;
/**
     * @brief Define um novo cartão para o hóspede.
     *
     * @param cartao Número do cartão a ser validado.
     */

    void setCartao(const std::string& cartao);
/**
     * @brief Retorna o cartão cadastrado do hóspede.
     *
     * @return Número do cartão em formato string.
     */
    std::string getCartao() const;

};


#endif // ENTIDADE_HOSPEDE_H_INCLUDED
