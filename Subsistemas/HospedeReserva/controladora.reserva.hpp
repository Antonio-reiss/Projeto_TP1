#ifndef CONTROLADORA_RESERVA_HPP_INCLUDED
#define CONTROLADORA_RESERVA_HPP_INCLUDED

#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"
#include "ma.reserva.hpp"
#include "ms.reserva.hpp"
#include <iostream>
#include <limits>

void opcoesReserva();
bool validarCriarReserva();
void validarEditarReserva();
void excluirReserva();

#endif

