/**
 * @file ia_reserva.hpp
 * @brief Interface que define operacoes de validacao para reservas no sistema de gestao hoteleira.
 *
 * Esta interface estabelece contratos para validacao de criacao, edicao e cancelamento
 * de reservas dentro do sistema. Implementacoes concretas devem garantir o cumprimento
 * das regras de negocio, incluindo evitar conflitos de datas e consistencia dos dados.
 *
 * @author Ester Andrade Sousa - 242012109
 */
#ifndef IA_RESERVA_HPP_INCLUDED
#define IA_RESERVA_HPP_INCLUDED
#include <string>

using namespace std;
/**
 * @class IAReserva
 * @brief Interface responsavel por validar operacoes relacionadas a reservas.
 */
class IAReserva {
public:
 /**
     * @brief Valida os dados para criar uma nova reserva.
     * @param codigoReserva Codigo único da reserva.
     * @param emailHospede Email do hospede que está realizando a reserva.
     * @param codigoHotel Codigo do hotel onde a reserva sera efetuada.
     * @param dataChegada Data de chegada no formato dd-MES-aaaa.
     * @param dataPartida Data de partida no mesmo formato.
     * @return true se a reserva puder ser criada com os dados fornecidos, false caso contrario.
     */
    virtual bool validarCriar(string&, string&, string&, string&, string&) = 0;
 /**
     * @brief Valida a atualizacao das datas de uma reserva já existente.
     * @param dataChegada Nova data de chegada.
     * @param dataPartida Nova data de partida.
     * @return true se a alteracao for valida e nao causar conflitos, false caso contrario.
     */
    virtual bool validarEditarDatas(string&, string&) = 0;
/**
     * @brief Valida o cancelamento de uma reserva.
     * @param codigoReserva Codigo identificador da reserva a ser cancelada.
     * @return true se o cancelamento for permitido, false caso contrario.
     */
    virtual bool validarCancelar(string&) = 0;
};

#endif // IA_RESERVA_HPP_INCLUDED
