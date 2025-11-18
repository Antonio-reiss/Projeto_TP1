/**
 * @file ma.reserva.hpp
 * @brief Declaracao da classe MAReserva, que valida operacoes de reserva.
 *
 * Esta classe define as validacoes para criar, editar datas e cancelar reservas,
 * utilizando os dominios Codigo, Data, Dinheiro e Email para garantir a consistencia
 * e seguranca dos dados na camada de servico.
 *
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef MA_RESERVA_HPP_INCLUDED
#define MA_RESERVA_HPP_INCLUDED

#include "ia.reserva.hpp"
#include "../dominios/dominios.codigo.hpp"
#include "../dominios/dominios.data.hpp"
#include "../dominios/dominios.dinheiro.hpp"
#include "../dominios/dominios.email.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @class MAReserva
 * @brief Implementa as regras de validacao para operacoes com reservas.
 *
 * Esta classe herda de IAReserva e valida os dados antes da criacao, edicao
 * e cancelamento de uma reserva. Ela utiliza classes dominio para garantir que
 * os dados estejam no formato correto e sigam as regras de negocio.
 */
class MAReserva : public IAReserva {
public:
    /**
     * @brief Valida os dados necessarios para criar uma reserva.
     *
     * @param codigo Codigo da reserva.
     * @param dataChegada Data de chegada no formato "DD-MMM-AAAA".
     * @param dataPartida Data de partida no formato "DD-MMM-AAAA".
     * @param valor Valor da reserva em string numerica.
     * @param emailHospede Email do hospede.
     * @return true se todos os campos forem validos; false caso contrario.
     */
    bool validarCriar(string&, string&, string&, string&, string&) override;

    /**
     * @brief Valida as novas datas de uma reserva.
     *
     * @param dataChegada Nova data de chegada.
     * @param dataPartida Nova data de partida.
     * @return true se as datas forem validas; false caso contrario.
     */
    bool validarEditarDatas(string&, string&) override;

    /**
     * @brief Valida o codigo de uma reserva antes de cancelar.
     *
     * @param codigo Codigo da reserva que deve ser cancelada.
     * @return true se o codigo for valido; false caso contrario.
     */
    bool validarCancelar(string&) override;
};

#endif // MA_RESERVA_HPP_INCLUDED

