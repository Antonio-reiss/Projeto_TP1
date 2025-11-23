#include "controladora.hospede.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

// ---------------- MENU PRINCIPAL ---------------- //

void opcoesHospede() {
    int op;
    do {
        limparTela();

        cout << "\n================================\n";
        cout << "         OPCOES HOSPEDE          \n";
        cout << "================================\n";
        cout << "[1] Listar hospedes\n";
        cout << "[2] Criar hospede\n";
        cout << "[3] Editar hospede\n";
        cout << "[4] Excluir hospede\n";
        cout << "[5] Sair\n";
        cout << "================================\n";
        cout << "-> Escolha uma opcao: ";

        cin >> op;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (op) {
        case 1:
            msHospede().listarHospedes();
            esperar(2);
            break;
        case 2:
            validarCriarHospede();
            break;
        case 3:
            validarEditarHospede();
            break;
        case 4:
            excluirHospede();
            break;
        case 5:
            return;
        default:
            cout << "Opcao invalida!\n";
            esperar(2);
        }

    } while (true);
}



// ---------------- CRIAR ---------------- //

bool validarCriarHospede() {
    MAHospede ma;
    msHospede ms;

    string nome, email, endereco, cartao;

    limparTela();
    cout << "==== Criar Hospede ====\n";

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Email: ";
    getline(cin, email);

    cout << "Endereco: ";
    getline(cin, endereco);

    cout << "Cartao: ";
    getline(cin, cartao);

    if (ma.validarCriar(nome, email, endereco, cartao)) {
        ms.criarHospede(nome, email, endereco, cartao);
        esperar(2);
        return true;
    }

    cout << "Dados invalidos.\n";
    esperar(2);
    return false;
}



// ---------------- EDITAR ---------------- //

void validarEditarHospede() {
    MAHospede ma;
    msHospede ms;

    string email, novoEndereco, novoCartao;

    limparTela();
    cout << "==== Editar Hospede ====\n";

    cout << "Email do hospede a editar:\n-> ";
    getline(cin, email);

    cout << "Novo endereco:\n-> ";
    getline(cin, novoEndereco);

    cout << "Novo cartao:\n-> ";
    getline(cin, novoCartao);

    if (!ma.validarEditar(email, novoEndereco, novoCartao)) {
        cout << "Dados invalidos.\n";
        esperar(2);
        return;
    }

    ms.editarHospede(email, novoEndereco, novoCartao);
    cout << "Atualizado com sucesso!\n";
    esperar(2);
}



// ---------------- EXCLUIR ---------------- //

void excluirHospede() {
    MAHospede ma;
    msHospede ms;

    string email;
    cout << "Email do hospede a excluir:\n-> ";
    getline(cin, email);

    if (!ma.validarExcluir(email)) {
        cout << "Email invalido.\n";
        esperar(2);
        return;
    }

    cout << "Confirmar exclusao? (s/n): ";
    string c;
    getline(cin, c);

    transform(c.begin(), c.end(), c.begin(), ::tolower);

    if (c == "s") {
        ms.excluirHospede(email);
        cout << "Excluido com sucesso!\n";
    } else {
        cout << "Cancelado.\n";
    }

    esperar(2);
}
