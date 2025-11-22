/**
 * @file ms.hospede.hpp
 * @brief Implementacao concreta do modulo de servico do Hospede.
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef MS_HOSPEDE_HPP_INCLUDED
#define MS_HOSPEDE_HPP_INCLUDED

#include "is.hospede.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"

#include "../../entidades/entidade.hospede.hpp"
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.cartao.hpp"

/**
 * @class msHospede
 * @brief Implementacao do modulo de servico responsavel pela gerencia de hospedes.
 *
 * Esta classe implementa a interface isHospede, oferecendo operacoes de criacao,
 * listagem, edicao e exclusao de registros de hospedes utilizando o banco de dados.
 */
class msHospede : public isHospede {

private:
    /**
     * @brief Instancia do banco de dados utilizada para armazenar e recuperar informacoes.
     */
    bancoDeDados db;

public:

    /**
     * @brief Cria um novo hospede no sistema.
     *
     * O metodo valida os dados recebidos por meio dos dominios e registra
     * o novo hospede na base de dados caso todos os valores sejam validos.
     *
     * @param string nome do hospede.
     * @param string email do hospede.
     * @param string endereco do hospede.
     * @param string cartao do hospede.
     * @return Retorna true se o hospede for criado com sucesso, false caso contrario.
     */
    bool criarHospede(const string&, const string&, const string&, const string&) override;

    /**
     * @brief Lista todos os hospedes cadastrados.
     *
     * O metodo acessa o banco de dados e exibe as informacoes de cada hospede.
     *
     * @return Retorna true se a listagem ocorrer corretamente, false caso contrario.
     */
    bool listarHospedes() override;

    /**
     * @brief Edita informacoes de um hospede existente.
     *
     * Permite atualizar campos especificos conforme a identificacao recebida.
     *
     * @param string identificador do hospede.
     * @param string novoDado valor atualizado.
     * @param string tipoDado tipo do dado que sera alterado.
     * @return Retorna true se a edicao for bem-sucedida, false caso contrario.
     */
    bool editarHospede(string, string, string) override;

    /**
     * @brief Exclui um hospede da base de dados.
     *
     * Remove permanentemente o registro associado ao identificador informado.
     *
     * @param string identificador do hospede.
     * @return Retorna true se a exclusao ocorrer corretamente, false caso contrario.
     */
    bool excluirHospede(const string&) override;

};

#endif // MS_HOSPEDE_HPP_INCLUDED
