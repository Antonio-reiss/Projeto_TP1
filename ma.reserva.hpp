#ifndef MA_RESERVA_HPP_INCLUDED
#define MA_RESERVA_HPP_INCLUDED

#include "ia.reserva.hpp"
#include "../dominios/dominios.codigo.hpp"
#include "../dominios/dominios.data.hpp"
#include "../dominios/dominios.dinheiro.hpp"
#include "../dominios/dominios.email.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class aReserva : public IAReserva {
public:
    bool validarCriar(string&, string&, string&, string&, string&) override;
    bool validarEditarDatas(string&, string&) override;
    bool validarCancelar(string&) override;
};

#endif // MA_RESERVA_HPP_INCLUDED
