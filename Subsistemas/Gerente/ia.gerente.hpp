#ifndef IA_GERENTE_HPP
#define IA_GERENTE_HPP
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.ramal.hpp"
#include "../../dominios/dominios.senha.hpp",
#include <string>

using namespace std;

class IAGerente{
public:
    virtual bool validarConta(const string&, const string&, const int&, const string&) = 0;
    //virtual bool validarEditar(const int& ramal);

};

#endif // IA_GERENTE_HPP
