/**
 * @file controladora.reserva.hpp
 * @brief Cabecalho da controladora do modulo de Reserva.
 *
 * Declara as funcoes responsaveis por intermediar a interacao entre a
 * apresentacao e as camadas de logica e servico, incluindo operacoes
 * de criacao, edicao, listagem e exclusao de reservas.
 * author Ester Andrade Sousa - 242012109
 */

#ifndef CONTROLADORA_RESERVA_HPP_INCLUDED
#define CONTROLADORA_RESERVA_HPP_INCLUDED

#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"
#include "ma.reserva.hpp"
#include "ms.reserva.hpp"
#include <iostream>
#include <limits>

/**
 * @brief Exibe o menu de opcoes relacionadas ao modulo de reserva.
 */
void opcoesReserva();

/**
 * @brief Valida e solicita os dados necessarios para criar uma nova reserva.
 *
 * @return true se os dados forem validados e a criacao for bem sucedida,
 * false caso contrario.
 */
bool validarCriarReserva();

/**
 * @brief Solicita e valida os dados necessarios para editar uma reserva.
 */
void validarEditarReserva();

/**
 * @brief Realiza o processo de exclusao de uma reserva com base no codigo informado.
 */
void excluirReserva();

#endif
