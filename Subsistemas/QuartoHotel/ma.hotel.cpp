#include "ma.hotel.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

bool aHotel::validarCriar(string& nome, string& endereco, string& telefone, string& codigo){
    try {
        Nome nomeValido(nome);
        Endereco enderecoValido(endereco);
        Telefone telefoneValido(telefone);
        Codigo codigoValido(codigo);
    }
    catch (const exception& error) {
        cout << error.what() << endl;
        return false;
    }
    return true;
}

bool aHotel::validarEditar(string& novoDado, string& tipoDado){
    try {
        if (tipoDado == "nome"){
            Nome nomeValido(novoDado);
        }
        else if (tipoDado == "endereco"){
            Endereco enderecoValido(novoDado);
        }
        else if (tipoDado == "telefone"){
            Telefone telefoneValido(novoDado);
        }
        else if (tipoDado == "codigo"){
            Codigo codigoValido(novoDado);
        }
    }
    catch (const exception& error) {
        cout << error.what() << endl;
        return false;
    }
    return true;
}
