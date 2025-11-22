/**
 * @file ic.reserva.hpp
 * @brief Interface de controle para o modulo de Reserva.
 *
 * Define as operacoes que a camada de controle deve implementar
 * para gerenciar reservas, incluindo criacao, listagem, edicao e exclusao.
 * Serve como ponte entre a camada de apresentacao e o servico de reservas.
 * author Ester Andrade Sousa - 242012109
 */
#ifndef IC_RESERVA_HPP_INCLUDED
#define IC_RESERVA_HPP_INCLUDED

#include <string>

/**
 * @class icReserva
 * @brief Interface de controle para operacoes de reserva.
 *
 * Define as operacoes essenciais relacionadas ao fluxo de reserva,
 * normalmente chamadas pela camada de apresentacao.
 */
class icReserva {
public:

    /**
     * @brief Cria uma nova reserva.
     *
     * @param codigo Codigo da reserva.
     * @param chegada Data de chegada.
     * @param partida Data de partida.
     * @param valor Valor monetario.
     * @param emailHospede Email do hospede associado.
     * @param numeroQuarto Numero do quarto associado.
     *
     * @return true se a reserva for criada com sucesso, false caso contrario.
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
     * @param codigo Codigo da reserva.
     * @param novaChegada Nova data de chegada.
     * @param novaPartida Nova data de partida.
     *
     * @return true se a atualizacao ocorrer com sucesso, false se falhar.
     */
    virtual bool editarReserva(const std::string&, const std::string&, const std::string&) = 0;

    /**
     * @brief Exclui uma reserva pelo codigo.
     *
     * @param codigo Codigo da reserva.
     *
     * @return true se a exclusao for bem sucedida, false em caso de erro.
     */
    virtual bool excluirReserva(const std::string&) = 0;

    virtual ~icReserva() {}
};

#endif
