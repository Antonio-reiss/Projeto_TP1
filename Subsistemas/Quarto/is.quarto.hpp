#ifndef IS_QUARTO_HPP_INCLUDED
#define IS_QUARTO_HPP_INCLUDED
#include "../funcoes.de.controles.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include "../../entidades/entidade.quarto.hpp"
#include "../../dominios/dominios.dinheiro.hpp"
#include "../../dominios/dominios.capacidade.hpp"
#include "../../dominios/dominios.numero.hpp"
#include "../../dominios/dominios.ramal.hpp"

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class isQuarto{
public:
    virtual bool criarQuarto(Quarto&, string&) = 0;
    virtual void listarQuarto() = 0;
    virtual void listarQuartoFiltro(string&) = 0;
    virtual bool updateQuarto(Quarto&, int, bool) = 0;
    virtual void apagarQuarto(int) = 0;
    virtual void apagarQuartos() = 0;
};

#endif // IS_QUARTO_HPP_INCLUDED
