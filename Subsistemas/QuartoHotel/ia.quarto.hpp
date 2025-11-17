#ifndef IA_QUARTO_HPP_INCLUDED
#define IA_QUARTO_HPP_INCLUDED
#include <string>

using namespace std;

template <typename T>
class iaQuarto{
public:
    virtual bool validarCriar(int&, int&, string&, int&) = 0;
    virtual bool validarEditar(T&, string&) = 0;
};

#endif // IA_QUARTO_HPP_INCLUDED
