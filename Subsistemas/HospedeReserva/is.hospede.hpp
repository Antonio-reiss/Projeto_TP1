/**
 * @file is.hospede.hpp
 * @brief Interface abstrata para o serviço de gerenciamento de hóspedes.
 *
 * Define o contrato para criação, listagem, edição e exclusão de hóspedes,
 * permitindo que diferentes implementações mantenham a mesma estrutura lógica.
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef IS_HOSPEDE_HPP_INCLUDED
#define IS_HOSPEDE_HPP_INCLUDED

#include <string>
using namespace std;



/**
 * @class isHospede
 * @brief Interface que define as operações essenciais do CRUD de hóspede.
 *
 * As classes que implementarem esta interface devem garantir validação dos
 * dados de entrada e integração com o mecanismo de persistencia adotado.
 */
class isHospede {
public:

    /**
     * @brief Cria um novo hóspede no sistema.
     *
     * @param nome nome do hóspede.
     * @param email email do hóspede (chave primária).
     * @param endereco endereço do hóspede.
     * @param cartao número do cartão associado.
     *
     * @return true se o cadastro for concluído com sucesso, false em falhas.
     */
    virtual bool criarHospede(const string&, const string&, const string&, const string&) = 0;

    /**
     * @brief Lista todos os hóspedes cadastrados.
     *
     * @return true se a operação ocorrer corretamente, false caso contrário.
     */
    virtual bool listarHospedes() = 0;

    /**
     * @brief Edita informações de um hóspede existente.
     *
     * @param emailChave email que identifica o hóspede a ser atualizado.
     * @param novoEndereco novo valor para o campo endereço.
     * @param novoCartao novo valor para o campo cartão.
     *
     * @return true se a edição for bem-sucedida, false em erro.
     */
    virtual bool editarHospede(string, string, string) = 0;

    /**
     * @brief Exclui um hóspede do sistema.
     *
     * @param email email do hóspede que será removido.
     *
     * @return true se a exclusão for concluída, false caso contrário.
     */
    virtual bool excluirHospede(const string&) = 0;
};

#endif // IS_HOSPEDE_HPP_INCLUDED
