/**
 * @file controladora.hospede.hpp
 * @brief Cabecalho da controladora do modulo de Hospede.
 *
 * Declara as funcoes responsaveis por intermediar a interacao entre a
 * apresentacao e as camadas de logica e servico, incluindo operacoes
 * de criacao, edicao, listagem e exclusao de hospedes.
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef CONTROLADORA_HOSPEDE_HPP_INCLUDED
#define CONTROLADORA_HOSPEDE_HPP_INCLUDED

#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"
#include "ma.hospede.hpp"
#include "ms.hospede.hpp"
#include <iostream>
#include <limits>

/**
 * @brief Exibe o menu de opcoes relacionadas ao modulo de hospede.
 */
void opcoesHospede();

/**
 * @brief Valida e solicita os dados necessarios para criar um novo hospede.
 *
 * @return true se os dados forem validados e a criacao for bem sucedida,
 * false caso contrario.
 */
bool validarCriarHospede();

/**
 * @brief Solicita e valida os dados necessarios para editar um hospede.
 */
void validarEditarHospede();

/**
 * @brief Realiza o processo de exclusao de um hospede com base no email informado.
 */
void excluirHospede();

#endif // CONTROLADORA_HOSPEDE_HPP_INCLUDED
