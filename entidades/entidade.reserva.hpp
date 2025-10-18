#ifndef ENTIDADE_RESERVA_HPP_INCLUDED
#define ENTIDADE_RESERVA_HPP_INCLUDED

#include "../dominios/dominios.data.hpp"
#include "../dominios/dominios.dinheiro.hpp"
#include <iostream>
#include <string>
using namespace std;

class Reserva
{
private:
    Data chegada;
    Data partida;
    Dinheiro valor;
    bool validarDatas(Data& , Data&);

public:
    inline Reserva(int diaChegada, string mesChegada, int anoChegada,
            int diaPartida, string mesPartida, int anoPartida,
            double valorDinheiro): chegada(diaChegada, mesChegada, anoChegada),
            partida(diaPartida, mesPartida, anoPartida),
            valor(valorDinheiro){
                validarDatas(this->chegada, this->partida);
            }
    void setReserva(Data, Data, double);
    void setChegada(Data);
    void setPartida(Data);
    void setValorDinheiro(double);
    string getChegada();
    string getPartida();
    double getValor();
};

#endif // ENTIDADES_RESERVA_H_INCLUDED
