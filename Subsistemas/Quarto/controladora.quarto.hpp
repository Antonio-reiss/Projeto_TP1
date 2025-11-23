#ifndef CONTROLADORA_QUARTO_HPP_INCLUDED
#define CONTROLADORA_QUARTO_HPP_INCLUDED
#include "../funcoes.de.controles.hpp"
#include "ma.quarto.hpp"
#include "ms.quarto.hpp"
#include "../../entidades/entidade.quarto.hpp"
#include "../../dominios/dominios.capacidade.hpp"
#include "../../dominios/dominios.dinheiro.hpp"
#include "../../dominios/dominios.numero.hpp"
#include "../../dominios/dominios.ramal.hpp"

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void opcoesQuarto();
void validarCriarQuarto();
void mostrarQuartos();
void editarQuarto();
void excluirQuarto();

#endif // CONTROLADORA_QUARTO_HPP_INCLUDED
