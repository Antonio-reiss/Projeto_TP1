#ifndef MA_HOSPEDE_HPP_INCLUDED
#define MA_HOSPEDE_HPP_INCLUDED

#include "ia.hospede.hpp"
#include "../dominios/dominios.nome.hpp"
#include "../dominios/dominios.email.hpp"
#include "../dominios/dominios.endereco.hpp"
#include "../dominios/dominios.cartao.hpp"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class aHospede : public IAHospede {
public:
    bool validarCriar(string&, string&, string&, string&) override;
    bool validarEditar(string&, string&, string&) override;
    bool validarExcluir(string&) override;
};

#endif // MA_HOSPEDE_HPP_INCLUDED

