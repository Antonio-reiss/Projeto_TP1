/**
* @file entidade.reserva.hpp
* @brief Definicao da Entidade Gerente.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef ENTIDADE_RESERVA_HPP_INCLUDED
#define ENTIDADE_RESERVA_HPP_INCLUDED

#include "../dominios/dominios.dinheiro.hpp"
#include "../dominios/dominios.codigo.hpp"
#include "../dominios/dominios.data.hpp"
#include <iostream>
#include <string>
using namespace std;

/**
* @class Reserva
* @brief Representa uma reserva de hospedagem com datas, valor e código.
*/
class Reserva
{
private:
    Data chegada;
    Data partida;
    Dinheiro valor;
    Codigo codigo;
    /**
    * @brief Valida se a data de chegada eh cronologicamente anterior ou igual a data de partida.
    * @param chegada referencia para o objeto data de chegada.
    * @param partida referencia para o objeto data de partida.
    * @return Retorna true se as datas forem validas, caso contrario lanca excecao.
    */
    bool validarDatas(Data& , Data&);

public:
    /**
    * @brief Construtor da classe Reserva.
    * @param diaChegada dia de chegada.
    * @param mesChegada mes de chegada.
    * @param anoChegada ano de chegada.
    * @param diaPartida dia de partida.
    * @param mesPartida mes de partida.
    * @param anoPartida ano de partida.
    * @param valorDinheiro valor total da reserva.
    * @param numCodigo codigo unico de reserva.
    */
    inline Reserva(int diaChegada, string mesChegada, int anoChegada,
            int diaPartida, string mesPartida, int anoPartida,
            double valorDinheiro, string numCodigo): chegada(diaChegada, mesChegada, anoChegada),
            partida(diaPartida, mesPartida, anoPartida),
            valor(valorDinheiro), codigo(numCodigo){
                validarDatas(this->chegada, this->partida);
    }
    /**
    * @brief Define todos os atributos da reserva (Data, Data, Valor e Codigo).
    * @param novaChegada objeto Data para a nova chegada.
    * @param novaPartida objeto Data para a nova partida.
    * @param novoValor novo valor da reserva.
    * @param novoCodigo novo codigo da reserva.
    */
    void setReserva(Data, Data, double, string);
    /**
    * @brief Define a data de chegada apos validacao.
    * @param novaChegada objeto Data para a nova chegada.
    */
    void setChegada(Data);
    /**
    * @brief Define a data de partida apos validacao.
    * @param novaPartida objeto Data para a nova partida.
    */
    void setPartida(Data);
    /**
    * @brief Define o valor monetario da reserva.
    * @param preco novo vaalor da reserva.
    */
    void setValorDinheiro(double);
    /**
    * @brief Define o codigo da reserva.
    * @param novoCodigo novo codigo da reserva.
    */
    void setCodigo(string);
    /**
    * @brief Retorna a data de chegada formatada (string).
    * @return Data de chegada.
    */
    string getChegada();
    /**
    * @brief Retorna a data de partida formatada (string).
    * @return Data de partida.
    */
    string getPartida();
    /**
    * @brief retorna o codigo de reserva.
    * @return codigo.
    */
    string getCodigo();
    /**
    * @brief Retorna o valor monetario da reserva.
    * @return valor como double.
    */
    double getValor();
};

#endif // ENTIDADES_RESERVA_H_INCLUDED
