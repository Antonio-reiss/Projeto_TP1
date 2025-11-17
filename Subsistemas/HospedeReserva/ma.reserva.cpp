/**
 * @file ma.reserva.cpp
 * @brief Implementacao das regras de validacao para criacao, edicao e cancelamento de reservas.
 * @author Ester Andrade Sousa - 242012109
 */
#include "ma.reserva.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

bool aReserva::validarCriar(string& codigo, string& dataChegada, string& dataPartida, string& valor, string& emailHospede) {
    try {
        Codigo codigoValido(codigo);
        Data chegadaValida(stoi(dataChegada.substr(0, 2)), dataChegada.substr(3, 3), stoi(dataChegada.substr(7, 4)));
        Data partidaValida(stoi(dataPartida.substr(0, 2)), dataPartida.substr(3, 3), stoi(dataPartida.substr(7, 4)));
        Dinheiro valorValido(stoi(valor));
        Email emailValido(emailHospede);
    }
    catch (const exception& e) {
        cout << "Erro ao validar reserva: " << e.what() << endl;
        return false;
    }

    cout << "Reserva criada com sucesso!" << endl;
    return true;
}

bool aReserva::validarEditarDatas(string& dataChegada, string& dataPartida) {
    try {
        Data chegadaValida(stoi(dataChegada.substr(0, 2)), dataChegada.substr(3, 3), stoi(dataChegada.substr(7, 4)));
        Data partidaValida(stoi(dataPartida.substr(0, 2)), dataPartida.substr(3, 3), stoi(dataPartida.substr(7, 4)));
    }
    catch (const exception& e) {
        cout << "Erro ao editar datas da reserva: " << e.what() << endl;
        return false;
    }

    cout << "Datas da reserva atualizadas com sucesso!" << endl;
    return true;
}

bool aReserva::validarCancelar(string& codigo) {
    try {
        Codigo codigoValido(codigo);
    }
    catch (const exception& e) {
        cout << "Erro ao cancelar reserva: " << e.what() << endl;
        return false;
    }

    cout << "Reserva cancelada com sucesso!" << endl;
    return true;
}
