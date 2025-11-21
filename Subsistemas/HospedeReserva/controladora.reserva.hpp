/**
 * @file controladora.reserva.hpp
 * @brief Controlador da camada de controle para reservas.
 *
 * Implementa a interface icReserva e atua como intermediário entre a
 * camada de apresentação e o serviço de reserva (msReserva).
 * Encapsula a lógica de fluxo e delega operações ao serviço.
 */

#ifndef CRTL_RESERVA_HPP_INCLUDED
#define CTRL_RESERVA_HPP_INCLUDED

#include "interface.controladora.reserva.h"
#include "ms.reserva.hpp"

/**
 * @class ctrlReserva
 * @brief Controlador de reservas.
 *
 * Implementa todas as operações da interface icReserva utilizando o
 * serviço msReserva para persistência e validação dos dados.
 */
class ctrlReserva : public icReserva {

private:
    /**
     * @brief Instância do serviço de reserva.
     */
    msReserva servico;

public:
    /**
     * @brief Cria uma nova reserva.
     *
     * @param codigo Código da reserva.
     * @param chegada Data de chegada.
     * @param partida Data de partida.
     * @param valor Valor monetário.
     * @param emailHospede Email do hóspede associado.
     * @param numeroQuarto Número do quarto associado.
     *
     * @return true se a reserva for criada com sucesso, false caso contrário.
     */
    bool criarReserva(const std::string&, const std::string&, const std::string&,
                      const std::string&, const std::string&, int) override;

    /**
     * @brief Lista todas as reservas cadastradas.
     *
     * @return true se a listagem ocorrer corretamente, false em caso de erro.
     */
    bool listarReservas() override;

    /**
     * @brief Edita as datas de uma reserva existente.
     *
     * @param codigo Código da reserva.
     * @param novaChegada Nova data de chegada.
     * @param novaPartida Nova data de partida.
     *
     * @return true se a edição for aplicada com sucesso, false caso contrário.
     */
    bool editarReserva(const std::string&, const std::string&, const std::string&) override;

    /**
     * @brief Exclui uma reserva pelo código.
     *
     * @param codigo Código da reserva.
     *
     * @return true se a exclusão ocorrer com sucesso, false em caso de falha.
     */
    bool excluirReserva(const std::string&) override;
};

#endif
