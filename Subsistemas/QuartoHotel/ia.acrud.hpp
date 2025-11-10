#ifndef IA_ACRUD_HPP_INCLUDED
#define IA_ACRUD_HPP_INCLUDED

#include <string>

using namespace std;

//Create, Read, Update, Delete
class aCrud {
public:
    template <typename T>
    virtual validarCriar(T&, T&, T&, T&) = 0;
    virtual validarEditar(T&) = 0;
};


#endif // IA_ACRUD_HPP_INCLUDED
