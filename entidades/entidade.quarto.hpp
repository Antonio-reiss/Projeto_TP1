#ifndef ENTIDADE_QUARTO_HPP_INCLUDED
#define ENTIDADE_QUARTO_HPP_INCLUDED

#include "../dominios/dominios.numero.hpp"
#include "../dominios/dominios.capacidade.hpp"
#include "../dominios/dominios.dinheiro.hpp"
#include "../dominios/dominios.capacidade.hpp"

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
