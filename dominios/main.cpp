#include "../entidades/entidade.reserva.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    int diaChegada, anoChegada, diaPartida, anoPartida;
    string mesChegada, mesPartida;
    double valor;

    cout << "Digite a data de chegada, no formato dd, \"mes\", aa" << endl;
    cin >> diaChegada >> mesChegada >> anoChegada;

    cout << "Digite a data de partida, no formato dd, \"mes\", aa" << endl;
    cin >> diaPartida >> mesPartida >> anoPartida;

    cout << "Digite o valor da reserva" << endl;
    cin >> valor;

    Reserva reserva(diaChegada, mesChegada, anoChegada, diaPartida, mesPartida, anoPartida, valor);

    cout << "Reserva:" << endl;
    cout << "Data chegada:" << endl;
    cout << reserva.getChegada() << endl;
    cout << endl;
    cout << "Data partida:" << endl;
    cout << reserva.getPartida() << endl;
    cout << endl;
    cout << "Valor: ";
    cout << reserva.getValor() << endl;

    return 0;
}
