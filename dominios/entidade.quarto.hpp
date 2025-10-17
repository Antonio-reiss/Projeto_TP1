#ifndef ENTIDADE_QUARTO_HPP_INCLUDED
#define ENTIDADE_QUARTO_HPP_INCLUDED
#include "dominios.numero.hpp"
#include "dominios.capacidade.hpp"
#include "dominios.dinheiro.hpp"
#include "dominios.ramal.hpp"

using namespace std;

class Quarto{
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;
public:
    Quarto(const int& numero, const int& capacidade, const string& diaria, const int& ramal);
    void setNumero(int numero);
    void setCapacidade(int capacidade);
    void setDiaria(const string& diaria);
    void setRamal(int ramal);
    int getNumero() const;
    int getCapacidade() const;
    double getDiaria() const;
    int getRamal() const;
};

#endif // ENTIDADE_QUARTO_HPP_INCLUDED
