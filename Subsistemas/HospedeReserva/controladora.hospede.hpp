#ifndef CONTROLADORA_HOSPEDE_HPP_INCLUDED
#define CONTROLADORA_HOSPEDE_HPP_INCLUDED

#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"
#include "ma.hospede.hpp"
#include "ms.hospede.hpp"
#include <iostream>
#include <limits>

void opcoesHospede();
bool validarCriarHospede();
void validarEditarHospede();
void excluirHospede();

#endif
