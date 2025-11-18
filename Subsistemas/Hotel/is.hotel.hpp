#ifndef IS_HOTEL_HPP_INCLUDED
#define IS_HOTEL_HPP_INCLUDED
#include "../../entidades/entidade.hotel.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.telefone.hpp"
#include "../../dominios/dominios.codigo.hpp"
#include "../../dominios/dominios.nome.hpp"

#include <string>
#include <iostream>

using namespace std;

class isHotel {
public:
    bool criarHotel() = 0;
    void listarHotel() = 0;
    void listarHotelFiltro(string&, string&) = 0;
    bool updateHotel() = 0;
    void apagarHotel() = 0;
    void apagarHoteis() = 0;
};

#endif // IS_HOTEL_HPP_INCLUDED
