#include "ma.quarto.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

bool maQuarto::validarCriar(int& numero, int& capacidade, string& diaria, int& ramal, string& codigo){
    try {
        Numero numeroValido(numero);
        Capacidade capacidadeValida(capacidade);
        Dinheiro diariaValida(diaria);
        Ramal ramalValido(ramal);
        Codigo codigoValido(codigo);
    }
    catch (const exception& error) {
        cout << error.what() << endl;
        return false;
    }
    return true;
}

bool maQuarto::validarEditar(int& novoDado, string tipoDado){
    try {
        if (tipoDado == "numero"){
            Numero numeroValido(novoDado);
        }
        else if (tipoDado == "capacidade"){
            Capacidade capacidadeValida(novoDado);
        }
        else if (tipoDado == "ramal"){
            Ramal ramalValido(novoDado);
        }
    }
    catch (const exception& error) {
        cout << error.what() << endl;
        return false;
    }
    return true;
}

bool maQuarto::validarEditar(string& diaria, string tipoDado){
    try {
        if(tipoDado == "codigo"){
            Codigo codigoValido(diaria);
        } else {
            Dinheiro diariaValida(diaria);
        }
    }
    catch (const exception& error) {
        cout << error.what() << endl;
        return false;
    }
    return true;
}
