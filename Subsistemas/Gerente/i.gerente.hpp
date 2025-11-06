#ifndef I_GERENTE_HPP
#define I_GERENTE_HPP
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp"
#include <string>

using namespace std;

class IGerente{
public:
    virtual bool validarConta(const string&, const string&, const float&, const string&) = 0;
};

#endif // IA_GERENTE_HPP
