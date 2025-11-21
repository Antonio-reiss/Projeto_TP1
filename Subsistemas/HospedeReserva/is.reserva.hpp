/**
 * @file is.reserva.hpp
 * @brief Interface abstrata para o módulo de serviço de Reserva (CRUD).
 *
 * Define o contrato que a camada de apresentação deve utilizar para lidar
 * com operações envolvendo reservas, garantindo consistência do sistema.
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef IS_RESERVA_HPP_INCLUDED
#define IS_RESERVA_HPP_INCLUDED

#include <string>
using namespace std;

/**
 * @class isReserva
 * @brief Interface que define as operações de CRUD da reserva.
 *
 * Implementações devem garantir validação dos dados de entrada e integração
 * com o mecanismo de persistência adotado.
 */
class isReserva {
public:

    /**
     * @brief Cria uma reserva.
     *
     * @param codigo Código da reserva (PK).
     * @param chegada Data de chegada (formato esperado: DD-MES-AAAA).
     * @param partida Data de partida (formato esperado: DD-MES-AAAA).
     * @param valor Valor monetário (representado como string).
     * @param emailHospede Email do hóspede associado à reserva.
     * @param numeroQuarto Número do quarto associado à reserva.
     *
     * @return true se a reserva for criada com sucesso, false caso ocorra erro.
     */
    virtual bool criarReserva(const string&, const string&, const string&, const string&, const string&, int) = 0;

    /**
     * @brief Lista todas as reservas cadastradas.
     *
     * @return true se a operação de listagem ocorrer corretamente, false em caso de falha.
     */
    virtual bool listarReservas() = 0;

    /**
     * @brief Edita apenas as datas de uma reserva identificada pelo código.
     *
     * @param codigo Código identificador da reserva a ser editada.
     * @param novaChegada Nova data de chegada (DD-MES-AAAA).
     * @param novaPartida Nova data de partida (DD-MES-AAAA).
     *
     * @return true se a edição for aplicada com sucesso, false caso contrário.
     */
    virtual bool editarReserva(string, string, string) = 0;

    /**
     * @brief Exclui reserva pelo código.
     *
     * @param codigo Código identificador da reserva que será removida.
     *
     * @return true se a exclusão for bem-sucedida, false em caso de falha.
     */
    virtual bool excluirReserva(const string&) = 0;

};

#endif // IS_RESERVA_HPP_INCLUDED
