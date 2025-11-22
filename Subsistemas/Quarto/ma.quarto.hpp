#ifndef MA_QUARTO_HPP_INCLUDED
#define MA_QUARTO_HPP_INCLUDED
#include "../../dominios/dominios.numero.hpp"
#include "../../dominios/dominios.capacidade.hpp"
#include "../../dominios/dominios.dinheiro.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "ia.quarto.hpp"
#include <string>

using namespace std;

class maQuarto : public iaQuarto<string>, public iaQuarto<int> {
public:
    bool validarCriar(int&, int&, string&, int&) override;
    bool validarEditar(int&, string&) override;
    bool validarEditar(string&, string&) override;
};

#endif // MA_QUARTO_HPP_INCLUDED
