/**
 * @file is.reserva.hpp
 * @brief Interface abstrata para o modulo de servico de Reserva (CRUD).
 *
 * Define o contrato que a camada de apresentacao deve utilizar para lidar
 * com operacoes envolvendo reservas, garantindo consistencia do sistema.
 * author Ester Andrade Sousa - 242012109
 */

#ifndef IS_RESERVA_HPP_INCLUDED
#define IS_RESERVA_HPP_INCLUDED

#include <string>
using namespace std;

/**
 * @class isReserva
 * @brief Interface que define as operacoes de CRUD da reserva.
 *
 * Implementacoes devem garantir validacao dos dados de entrada e integracao
 * com o mecanismo de persistencia adotado.
 */
class isReserva {
public:

    /**
     * @brief Cria uma reserva.
     *
     * @param codigo Codigo da reserva (PK).
     * @param chegada Data de chegada (formato esperado: DD-MES-AAAA).
     * @param partida Data de partida (formato esperado: DD-MES-AAAA).
     * @param valor Valor monetario (representado como string).
     * @param emailHospede Email do hospede associado a reserva.
     * @param numeroQuarto Numero do quarto associado a reserva.
     *
     * @return true se a reserva for criada com sucesso, false caso ocorra erro.
     */
    virtual bool criarReserva(const string&, const string&, const string&, const string&, const string&, int) = 0;

    /**
     * @brief Lista todas as reservas cadastradas.
     *
     * @return true se a operacao de listagem ocorrer corretamente, false em caso de falha.
     */
    virtual bool listarReservas() = 0;

    /**
     * @brief Edita apenas as datas de uma reserva identificada pelo codigo.
     *
     * @param codigo Codigo identificador da reserva a ser editada.
     * @param novaChegada Nova data de chegada (DD-MES-AAAA).
     * @param novaPartida Nova data de partida (DD-MES-AAAA).
     *
     * @return true se a edicao for aplicada com sucesso, false caso contrario.
     */
    virtual bool editarReserva(string, string, string) = 0;

    /**
     * @brief Exclui uma reserva pelo codigo.
     *
     * @param codigo Codigo identificador da reserva que sera removida.
     *
     * @return true se a exclusao for bem sucedida, false em caso de falha.
     */
    virtual bool excluirReserva(const string&) = 0;

};

#endif // IS_RESERVA_HPP_INCLUDED

