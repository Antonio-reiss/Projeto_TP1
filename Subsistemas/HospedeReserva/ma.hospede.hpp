/**
 * @file ma.hospede.hpp
 * @brief Declaracao da classe MAHospede, responsavel por validar as operacoes
 * de criacao, edicao e exclusao de hospedes na camada de servico.
 *
 * Esta classe utiliza objetos das classes dominio (Nome, Email, Endereco, Cartao)
 * para validar os dados antes de enviar para o banco ou outra camada do sistema.
 *
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef MA_HOSPEDE_HPP_INCLUDED
#define MA_HOSPEDE_HPP_INCLUDED

#include "ia.hospede.hpp"
#include "../dominios/dominios.nome.hpp"
#include "../dominios/dominios.email.hpp"
#include "../dominios/dominios.endereco.hpp"
#include "../dominios/dominios.cartao.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @class MAHospede
 * @brief Implementa a interface IAHospede para validacao de dados de hospedes.
 *
 * Esta classe valida os dados inseridos para que atendam aos requisitos
 * especificados pelas classes dominio antes de serem persistidos ou manipulados
 * em camadas superiores.
 */
class MAHospede : public IAHospede {
public:
    /**
     * @brief Valida os dados para criacao de um novo hospede.
     * @param nome Nome do hospede.
     * @param email Email do hospede.
     * @param endereco Endereco do hospede.
     * @param cartao Numero do cartao do hospede.
     * @return true se todos os dados forem validos, false caso contrario.
     */
    bool validarCriar(string&, string&, string&, string&) override;

    /**
     * @brief Valida os dados para edicao de um hospede existente.
     * @param email Novo email.
     * @param endereco Novo endereco.
     * @param cartao Novo numero do cartao.
     * @return true se os dados forem validos, false se algum campo estiver invalido.
     */
    bool validarEditar(string&, string&, string&) override;

    /**
     * @brief Valida os dados para exclusao de um hospede.
     * @param email Email do hospede que sera excluido.
     * @return true se o email for valido, false caso contrario.
     */
    bool validarExcluir(string&) override;
};

#endif // MA_HOSPEDE_HPP_INCLUDED
