/**
 * @file ic.reserva.hpp
 * @brief Interface de controle para o módulo de Reserva.
 *
 * Define as operações que a camada de controle deve implementar
 * para gerenciar reservas, incluindo criação, listagem, edição e exclusão.
 * Serve como ponte entre a camada de apresentação e o serviço de reservas.
 * @author Ester Andrade Sousa - 242012109
 */
#ifndef IC_RESERVA_HPP_INCLUDED
#define IC_RESERVA_HPP_INCLUDED

#include <string>

/**
 * @class icReserva
 * @brief Interface de controle para operações de reserva.
 *
 * Define as operações essenciais relacionadas ao fluxo de reserva,
 * normalmente chamadas pela camada de apresentação.
 */
class icReserva {
public:

    /**
     * @brief Cria uma nova reserva.
     *
     * @param codigo Código da reserva.
     * @param chegada Data de chegada.
     * @param partida Data de partida.
     * @param valor Valor monetário.
     * @param emailHospede E-mail do hóspede associado.
     * @param numeroQuarto Número do quarto associado.
     *
     * @return true se a reserva for criada com sucesso, false caso contrário.
     */
    virtual bool criarReserva(const std::string&, const std::string&, const std::string&,
                              const std::string&, const std::string&, int) = 0;

    /**
     * @brief Lista todas as reservas cadastradas.
     *
     * @return true se a listagem ocorrer corretamente, false em caso de erro.
     */
    virtual bool listarReservas() = 0;

    /**
     * @brief Edita as datas de uma reserva existente.
     *
     * @param codigo Código da reserva.
     * @param novaChegada Nova data de chegada.
     * @param novaPartida Nova data de partida.
     *
     * @return true se a atualização ocorrer com sucesso, false se falhar.
     */
    virtual bool editarReserva(const std::string&, const std::string&, const std::string&) = 0;

    /**
     * @brief Exclui uma reserva pelo código.
     *
     * @param codigo Código da reserva.
     *
     * @return true se a exclusão for bem-sucedida, false em caso de erro.
     */
    virtual bool excluirReserva(const std::string&) = 0;

    virtual ~icReserva() {}
};

#endif
