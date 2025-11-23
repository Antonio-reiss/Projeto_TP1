#ifndef MS_HOTEL_HPP_INCLUDED
#define MS_HOTEL_HPP_INCLUDED
#include "is.hotel.hpp"

class msHotel : isHotel {
public:
    bool criarHotel(Hotel&, string&) override;
    void listarHotel() override;
    void listarHotelFiltro(string&) override;
    bool updateHotel(Hotel&, string&) override;
    void apagarHotel(string&) override;
    void apagarHoteis() override;
};

#endif // MS_HOTEL_HPP_INCLUDED
