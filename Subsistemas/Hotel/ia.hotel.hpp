#ifndef IA_HOTEL_HPP_INCLUDED
#define IA_HOTEL_HPP_INCLUDED
#include <string>

using namespace std;

class iaHotel{
public:
    virtual bool validarCriar(string&, string&, string&, string&) = 0;
    virtual bool validarEditar(string&, string&) = 0;
};

#endif // IA_HOTEL_HPP_INCLUDED
