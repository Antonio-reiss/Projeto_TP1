#include "../Subsistemas/QuartoHotel/ma.hotel.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string nome, endereco, codigo, telefone;
    aHotel auth;

    getline(cin, nome);
    getline(cin, endereco);
    getline(cin, telefone);
    getline(cin, codigo);

    bool valido = auth.validarCriar(nome, endereco, telefone, codigo);

    if (valido) {
        cout << "Deu certo" << endl;
    }
    else{
        cout << "Deu errado" << endl;
    }


    return 0;
}

