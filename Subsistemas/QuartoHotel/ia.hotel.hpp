#ifndef IA_HOTEL_HPP_INCLUDED
#define IA_HOTEL_HPP_INCLUDED
#include "ia.acrud.hpp"
#include <string>

using namespace std;

class IHotel : public aCrud<string> {
public:
    virtual bool validarCriar(string&, string&, string&, string&) = 0;
    virtual bool validarEditar(string&, string&) = 0;
};

#endif // IA_HOTEL_HPP_INCLUDED
