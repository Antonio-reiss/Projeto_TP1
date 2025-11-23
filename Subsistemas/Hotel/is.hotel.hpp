#ifndef IS_HOTEL_HPP_INCLUDED
#define IS_HOTEL_HPP_INCLUDED
#include "../funcoes.de.controles.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include "../../entidades/entidade.hotel.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.telefone.hpp"
#include "../../dominios/dominios.codigo.hpp"
#include "../../dominios/dominios.nome.hpp"

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class isHotel {
public:
    virtual bool criarHotel(Hotel&, string&) = 0;
    virtual void listarHotel() = 0;
    virtual void listarHotelFiltro(string&) = 0;
    virtual bool updateHotel(Hotel&, string&) = 0;
    virtual void apagarHotel(string&) = 0;
    virtual void apagarHoteis() = 0;
};

#endif // IS_HOTEL_HPP_INCLUDED
