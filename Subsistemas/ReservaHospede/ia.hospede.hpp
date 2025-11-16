#ifndef IA_HOSPEDE_HPP_INCLUDED
#include <string>
#include <exception>

using namespace std;

class iaHospede{
public:
    virtual bool validarHospede(const string&, const string&, const string&, const string&) = 0;
    virtual bool validarEditar(const string&, const string&) = 0;
};

#endif // IA_HOSPEDE_HPP_INCLUDED
