/**
 * @file ma.hospede.hpp
 * @brief Declaracao da classe MAHospede, responsavel por validar operacoes
 * de criacao, edicao e exclusao de hospedes na camada de servico.
 *
 * Esta classe utiliza objetos dos dominios (Nome, Email, Endereco e Cartao)
 * para verificar a integridade dos dados antes de serem manipulados por camadas
 * superiores ou persistidos.
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
 * @brief Implementa a interface IAHospede para validacao de dados referentes a hospedes.
 *
 * Os metodos utilizam os dominios especificos para validar cada campo,
 * garantindo que os dados atendam aos requisitos antes de operacoes de
 * criacao, edicao ou exclusao.
 */
class MAHospede : public IAHospede {
public:

    /**
     * @brief Valida os dados para criacao de um novo hospede.
     *
     * Cada campo e analisado pelo seu dominio correspondente. Se algum dado
     * for invalido, o metodo retorna false.
     *
     * @param nome Nome do hospede.
     * @param email Email do hospede.
     * @param endereco Endereco do hospede.
     * @param cartao Numero do cartao do hospede.
     * @return true se todos os campos forem validos, false caso contrario.
     */
    bool validarCriar(string&, string&, string&, string&) override;

    /**
     * @brief Valida os dados para edicao de um hospede existente.
     *
     * A verificacao e feita individualmente para cada campo a ser alterado.
     *
     * @param email Email do hospede (nao necessariamente alterado).
     * @param endereco Novo endereco.
     * @param cartao Novo numero de cartao.
     * @return true se todos os dados forem validos, false caso contrario.
     */
    bool validarEditar(const string& email,
                       const string& endereco,
                       const string& cartao);

    /**
     * @brief Valida os dados para exclusao de um hospede.
     *
     * Apenas verifica se o email atende aos criterios do dominio.
     *
     * @param email Email do hospede a ser excluido.
     * @return true se o email for valido, false caso contrario.
     */
    bool validarExcluir(string&) override;

    /**
     * @brief Valida apenas o nome do hospede.
     * @param nome Nome a ser validado.
     * @return true se valido, false caso contrario.
     */
    bool validarNome(const string&);

    /**
     * @brief Valida apenas o email do hospede.
     * @param email Email a ser validado.
     * @return true se valido, false caso contrario.
     */
    bool validarEmail(const string&);

    /**
     * @brief Valida apenas o endereco do hospede.
     * @param endereco Endereco a ser validado.
     * @return true se valido, false caso contrario.
     */
    bool validarEndereco(const string&);

    /**
     * @brief Valida apenas o numero do cartao.
     * @param cartao Numero do cartao a ser validado.
     * @return true se valido, false caso contrario.
     */
    bool validarCartao(const string&);
};

#endif // MA_HOSPEDE_HPP_INCLUDED
