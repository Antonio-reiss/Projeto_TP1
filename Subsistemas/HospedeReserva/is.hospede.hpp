/**
 * @file is.hospede.hpp
 * @brief Interface abstrata para o servico de gerenciamento de hospedes.
 *
 * Define o contrato para criacao, listagem, edicao e exclusao de hospedes,
 * permitindo que diferentes implementacoes mantenham a mesma estrutura logica.
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef IS_HOSPEDE_HPP_INCLUDED
#define IS_HOSPEDE_HPP_INCLUDED

#include <string>
using namespace std;

/**
 * @class isHospede
 * @brief Interface que define as operacoes essenciais do CRUD de hospede.
 *
 * As classes que implementarem esta interface devem garantir validacao dos
 * dados de entrada e integracao com o mecanismo de persistencia adotado.
 */
class isHospede {
public:

    /**
     * @brief Cria um novo hospede no sistema.
     *
     * @param nome nome do hospede.
     * @param email email do hospede (chave primaria).
     * @param endereco endereco do hospede.
     * @param cartao numero do cartao associado.
     *
     * @return true se o cadastro for concluido com sucesso, false em falhas.
     */
    virtual bool criarHospede(const string&, const string&, const string&, const string&) = 0;

    /**
     * @brief Lista todos os hospedes cadastrados.
     *
     * @return true se a operacao ocorrer corretamente, false caso contrario.
     */
    virtual bool listarHospedes() = 0;

    /**
     * @brief Edita informacoes de um hospede existente.
     *
     * @param emailChave email que identifica o hospede a ser atualizado.
     * @param novoEndereco novo valor para o campo endereco.
     * @param novoCartao novo valor para o campo cartao.
     *
     * @return true se a edicao for bem sucedida, false em erro.
     */
    virtual bool editarHospede(string, string, string) = 0;

    /**
     * @brief Exclui um hospede do sistema.
     *
     * @param email email do hospede que sera removido.
     *
     * @return true se a exclusao for concluida, false caso contrario.
     */
    virtual bool excluirHospede(const string&) = 0;
};

#endif // IS_HOSPEDE_HPP_INCLUDED
