/**
 * @file entidade.hospede.hpp
 * @brief Declaracao da classe Hospede, que representa um usuario do sistema de hospedagem.
 *
 * Esta classe estende Pessoa e adiciona informacoes especificas de hospedes,
 * como endereco e cartao de credito, utilizando classes de dominio para garantir
 * validacoes consistentes e seguras.
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
 * @brief Representa um hospede, estendendo os dados basicos de Pessoa.
 *
 * A classe Hospede armazena e valida informacoes adicionais, como endereco
 * e cartao, utilizando os dominios correspondentes. Esta entidade e usada
 * nas operacoes ligadas a reservas e ao gerenciamento de usuarios.
 */
class Hospede : public Pessoa {
private:
    Endereco endereco;  ///< Endereco validado pelo dominio Endereco
    Cartao cartao;      ///< Cartao validado pelo dominio Cartao

public:

    /**
     * @brief Construtor completo do hospede.
     *
     * Realiza validacao de todos os campos utilizando os dominios
     * antes de construir o objeto.
     *
     * @param nome Nome do hospede.
     * @param email Email do hospede.
     * @param endereco Endereco do hospede.
     * @param cartao Numero do cartao do hospede.
     */
    Hospede(const std::string& nome,
            const std::string& email,
            const std::string& endereco,
            const std::string& cartao);

    /**
     * @brief Construtor padrao usado na montagem inicial do banco.
     *
     * Cria um objeto com valores genericos para permitir operacoes
     * de leitura e montagem sem necessidade de validacao imediata.
     */
    Hospede()
        : Pessoa("AAAAA", "aaaaa@aaaaa.com"),
          endereco("Rua A 123"),
          cartao("1111111111111111") {}

    /**
     * @brief Define o endereco do hospede apos validacao.
     * @param endereco Endereco a ser atribuido.
     */
    void setEndereco(const std::string& endereco);

    /**
     * @brief Retorna o endereco do hospede.
     * @return Endereco atual.
     */
    std::string getEndereco() const;

    /**
     * @brief Define o cartao do hospede apos validacao.
     * @param cartao Numero do cartao.
     */
    void setCartao(const std::string& cartao);

    /**
     * @brief Retorna o cartao do hospede.
     * @return Numero do cartao atual.
     */
    std::string getCartao() const;
};

#endif // ENTIDADE_HOSPEDE_H_INCLUDED

