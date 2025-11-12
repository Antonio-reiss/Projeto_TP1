#ifndef IA_RESERVA_HPP_INCLUDED
#define IA_RESERVA_HPP_INCLUDED
#include <string>

using namespace std;

class IAReserva {
public:
    virtual bool validarCriar(string&, string&, string&, string&, string&) = 0;
    virtual bool validarEditarDatas(string&, string&) = 0;
    virtual bool validarCancelar(string&) = 0;
};

#endif // IA_RESERVA_HPP_INCLUDED
