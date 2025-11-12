#ifndef IA_HOSPEDE_HPP_INCLUDED
#define IA_HOSPEDE_HPP_INCLUDED
#include <string>

using namespace std;

class IAHospede {
public:
    virtual bool validarCriar(string&, string&, string&, string&) = 0;
    virtual bool validarEditar(string&, string&, string&) = 0;
    virtual bool validarExcluir(string&) = 0;
};

#endif // IA_HOSPEDE_HPP_INCLUDED
