#ifndef IA_ACRUD_HPP_INCLUDED
#define IA_ACRUD_HPP_INCLUDED

#include <string>

using namespace std;

//Create, Read, Update, Delete
    template <typename T>
class aCrud {
public:
    virtual bool validarCriar(T&, T&, T&, T&) = 0;
    virtual bool validarEditar(T&, string&) = 0;
};


#endif // IA_ACRUD_HPP_INCLUDED
