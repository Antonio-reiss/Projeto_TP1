#ifndef MA_HOTEL_HPP_INCLUDED
#define MA_HOTEL_HPP_INCLUDED
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.telefone.hpp"
#include "../../dominios/dominios.codigo.hpp"
#include "ia.hotel.hpp"
#include <string>

using namespace std;

class maHotel : public iaHotel {
public:
    bool validarCriar(string&, string&, string&, string&) override;
    bool validarEditar(string&, string&) override;
};

#endif // MA_HOTEL_HPP_INCLUDED
