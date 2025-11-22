/**
 * @file controladora.reserva.cpp
 * @brief Implementacao das funcoes de controle do modulo de Reserva.
 * @author Ester Andrade Sousa - 242012109
 */

#include "controladora.reserva.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// ---------------- MENU PRINCIPAL RESERVA ---------------- //

void opcoesReserva() {
    msReserva servico;

    while (true) {
        limparTela();

        cout << "\n================================\n";
        cout << "        OPCOES DE RESERVA        \n";
        cout << "================================\n";
        cout << "[1] Listar reservas\n";
        cout << "[2] Criar reserva\n";
        cout << "[3] Editar datas da reserva\n";
        cout << "[4] Excluir reserva\n";
        cout << "[5] Voltar\n";
        cout << "================================\n";
        cout << "-> Escolha uma opcao: ";

        int op;
        if (cin >> op) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch (op) {
            case 1:
                servico.listarReservas();
                esperar(2);
                break;
            case 2:
                validarCriarReserva();
                break;
            case 3:
                validarEditarReserva();
                break;
            case 4:
                excluirReserva();
                break;
            case 5:
                return;
            default:
                cout << "Opcao invalida!\n";
                esperar(2);
            }
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// ---------------- CRIAR RESERVA ---------------- //

bool validarCriarReserva() {
    MAReserva validar;
    msReserva servico;

    string codigo, chegada, partida, valor, email;
    int numeroQuarto = 0;

    while (true) {
        limparTela();
        cout << "==== Criar Reserva ====\n";

        cout << "Codigo da reserva: ";
        getline(cin, codigo);

        cout << "Data de chegada (DD-MES-AAAA): ";
        getline(cin, chegada);

        cout << "Data de partida (DD-MES-AAAA): ";
        getline(cin, partida);

        cout << "Valor (somente numeros): ";
        getline(cin, valor);

        cout << "Email do hospede: ";
        getline(cin, email);

        cout << "Numero do quarto: ";
        cin >> numeroQuarto;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (validar.validarCriar(codigo, chegada, partida, valor, email)) {
            servico.criarReserva(codigo, chegada, partida, valor, email, numeroQuarto);
            cout << "Reserva criada!\n";
            esperar(2);
            return true;
        }
        else {
            cout << "Dados invalidos. Tente novamente.\n";
            esperar(2);
        }
    }
}

// ---------------- EDITAR RESERVA ---------------- //

void validarEditarReserva() {
    MAReserva validar;
    msReserva servico;

    string codigo;
    cout << "Codigo da reserva a editar:\n-> ";
    getline(cin, codigo);

    string novaChegada, novaPartida;

    cout << "Nova data de chegada (DD-MES-AAAA): ";
    getline(cin, novaChegada);

    cout << "Nova data de partida (DD-MES-AAAA): ";
    getline(cin, novaPartida);

    if (validar.validarEditarDatas(novaChegada, novaPartida)) {
        servico.editarReserva(codigo, novaChegada, novaPartida);
        cout << "Reserva atualizada!\n";
    } else {
        cout << "Erro na validacao.\n";
    }

    esperar(2);
}

// ---------------- EXCLUIR RESERVA ---------------- //

void excluirReserva() {
    MAReserva validar;
    msReserva servico;

    string codigo;
    cout << "Codigo da reserva a excluir:\n-> ";
    getline(cin, codigo);

    if (!validar.validarCancelar(codigo)) {
        cout << "Codigo invalido!\n";
        esperar(2);
        return;
    }

    cout << "Confirmar exclusao? (s/n): ";
    string c;
    getline(cin, c);
    transform(c.begin(), c.end(), c.begin(), ::tolower);

    if (c == "s") {
        servico.excluirReserva(codigo);
        cout << "Reserva excluida.\n";
    }
    else {
        cout << "Cancelado.\n";
    }

    esperar(2);
}
