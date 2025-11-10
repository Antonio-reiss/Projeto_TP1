#ifndef IA_QUARTO_HPP_INCLUDED
#define IA_QUARTO_HPP_INCLUDED
#include "ia.acrud.hpp"
#include <string>

using namespace std;

template <typename T>
class IQuarto : aCrud<T> {
public:
    virtual bool validarCriar(int&, int&, string&, int&) = 0;
    virtual bool validarEditar(T&, string&);
};

#endif // IA_QUARTO_HPP_INCLUDED
