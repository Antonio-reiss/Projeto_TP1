#ifndef MA_HOSPEDE_HPP_INCLUDED
#define MA_HOSPEDE_HPP_INCLUDED
#define IA_HOSPEDE_HPP_INCLUDED
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.cartao.hpp"
#include "ia.hospede.hpp"

using namespace std;

class maHospede : public iaHospede{
public:
    bool validarHospede(const string&, const string&, const string&, const string&) override;
    bool validarEditar(const string&, const string&) override;
};


#endif // MA_HOSPEDE_HPP_INCLUDED
