#ifndef ENTIDADE_RESERVA_HPP_INCLUDED
#define ENTIDADE_RESERVA_HPP_INCLUDED

#include "../dominios/dominios.dinheiro.hpp"
#include "../dominios/dominios.codigo.hpp"
#include "../dominios/dominios.data.hpp"
#include <iostream>
#include <string>
using namespace std;

class Reserva
{
private:
    Data chegada;
    Data partida;
    Dinheiro valor;
    Codigo codigo;
    bool validarDatas(Data& , Data&);

public:
    inline Reserva(int diaChegada, string mesChegada, int anoChegada,
            int diaPartida, string mesPartida, int anoPartida,
            double valorDinheiro, string numCodigo): chegada(diaChegada, mesChegada, anoChegada),
            partida(diaPartida, mesPartida, anoPartida),
            valor(valorDinheiro), codigo(numCodigo){
                validarDatas(this->chegada, this->partida);
            }
    void setReserva(Data, Data, double, string);
    void setChegada(Data);
    void setPartida(Data);
    void setValorDinheiro(double);
    void setCodigo(string);
    string getChegada();
    string getPartida();
    string getCodigo();
    double getValor();
};

#endif // ENTIDADES_RESERVA_H_INCLUDED
