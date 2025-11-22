/**
 * @file ms.reserva.cpp
 * @brief Implementacao dos metodos de servico da classe msReserva.
 * @author Ester Andrade Sousa - 242012109
 */

#include "ma.reserva.hpp"
#include "ms.reserva.hpp"
#include <string>
#include <sstream>

using namespace std;

static void parseData(const string& dataStr, int& dia, string& mes, int& ano) {
    char s1, s2;
    stringstream ss(dataStr);
    ss >> dia >> s1 >> mes >> s2 >> ano;

    if (!ss || s1 != '-' || s2 != '-') {
        throw invalid_argument("Formato invalido! Use DD-MES-AAAA.");
    }
}

bool msReserva::criarReserva(const string& codigoStr,
                             const string& chegadaStr,
                             const string& partidaStr,
                             const string& valorStr,
                             const string& emailHospede,
                             int numeroQuarto)
{
    try {

        Codigo codigo(codigoStr);
        Email email(emailHospede);
        Dinheiro valor(stod(valorStr));


        int dc, ac, dp, ap;
        string mc, mp;

        parseData(chegadaStr, dc, mc, ac);
        parseData(partidaStr, dp, mp, ap);


        Reserva reserva(
            dc, mc, ac,
            dp, mp, ap,
            valor.getValor(),
            codigo.getValor()
        );


        return db.criarReserva(reserva, numeroQuarto, email.getEmail());
    }
    catch (exception& e) {
        cout << "Erro ao criar reserva: " << e.what() << endl;
        return false;
    }
}

bool msReserva::listarReservas()
{
    try {
        db.listarTodos("Reserva");
        return true;
    }
    catch (exception& e) {
        cout << "Erro ao listar reservas: " << e.what() << endl;
        return false;
    }
}


bool msReserva::editarReserva(string codigoStr,
                              string novaChegadaStr,
                              string novaPartidaStr)
{
    try {
        Codigo codigo(codigoStr);

        int dc, ac, dp, ap;
        string mc, mp;

        parseData(novaChegadaStr, dc, mc, ac);
        parseData(novaPartidaStr, dp, mp, ap);


        Reserva r(
            dc, mc, ac,
            dp, mp, ap,
            0.0,
            codigo.getValor()
        );

        db.editarReserva(r, codigoStr);
        return true;
    }
    catch (exception& e) {
        cout << "Erro ao editar reserva: " << e.what() << endl;
        return false;
    }
}

bool msReserva::excluirReserva(const string& codigo)
{
    try {
        db.apagarUm("Reserva", "codigo", codigo);
        return true;
    }
    catch (exception& e) {
        cout << "Erro ao excluir reserva: " << e.what() << endl;
        return false;
    }
}
