#ifndef CONTROLADORA_HOTEL_HPP_INCLUDED
#define CONTROLADORA_HOTEL_HPP_INCLUDED
#include "../funcoes.de.controles.hpp"
#include "../../entidades/entidade.hotel.hpp"
#include "../../dominios/dominios.codigo.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.telefone.hpp"
#include "../../dominios/dominios.nome.hpp"

using namespace std;

void opcoesHotel();
void validarCriarHotel();
void mostrarHoteis();
void mostrarUmHotel();
void editarHotel();
void excluirHotel();

#endif // CONTROLADORA_HOTEL_HPP_INCLUDED
