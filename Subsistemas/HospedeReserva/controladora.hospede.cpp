/**
 * @file controladora.hospede.cpp
 * @brief Implementação das operaçoes de apresentaçao para gerenciamento de hospedes.
 * @author Ester Andrade Sousa - 242012109
 */

#include "controladora.hospede.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

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


bool validarCriarHospede() {
    MAHospede ma;
    msHospede ms;

    string nome, email, endereco, cartao;

    limparTela();
    cout << "==== Criar Hospede ====\n";

    // Valida nome
    while (true) {
        cout << "Nome: ";
        getline(cin, nome);

        if (ma.validarCriar(nome, "teste@teste.com", "Endereco valido", "1111222233334444")) {
            break;
        }

        cout << "Nome invalido! Tente novamente.\n\n";
    }

    // Valida email
    while (true) {
        cout << "Email: ";
        getline(cin, email);

        if (ma.validarCriar(nome, email, "Endereco valido", "1111222233334444")) {
            break;
        }

        cout << "Email invalido! Tente novamente.\n\n";
    }

    // Valida endereço
    while (true) {
        cout << "Endereco: ";
        getline(cin, endereco);

        if (ma.validarCriar(nome, email, endereco, "1111222233334444")) {
            break;
        }

        cout << "Endereco invalido! Tente novamente.\n\n";
    }

    // Valida cartão
    while (true) {
        cout << "Cartao: ";
        getline(cin, cartao);

        if (ma.validarCriar(nome, email, endereco, cartao)) {
            break;
        }

        cout << "Cartao invalido! Tente novamente.\n\n";
    }

    // Validação final
    if (!ma.validarCriar(nome, email, endereco, cartao)) {
        cout << "Erro inesperado na validacao.\n";
        esperar(2);
        return false;
    }

    ms.criarHospede(nome, email, endereco, cartao);

    cout << "Hospede criado com sucesso!\n";
    esperar(2);

    return true;
}

void validarEditarHospede() {
    MAHospede ma;
    msHospede ms;

    string email;
    limparTela();
    cout << "==== Editar Hospede ====\n";

    cout << "Email do hospede a editar:\n-> ";
    getline(cin, email);

    if (!ma.validarExcluir(email)) {
        cout << "Email invalido.\n";
        esperar(2);
        return;
    }

    int opcao = 0;
    do {
        limparTela();
        cout << "==== O que deseja editar? ====\n";
        cout << "[1] Endereco\n";
        cout << "[2] Cartao\n";
        cout << "[3] Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcao == 1) {
            string novoEndereco;
            cout << "Novo endereco:\n-> ";
            getline(cin, novoEndereco);

            bool valido = ma.validarEditar(email, novoEndereco, "");

            if (!valido) {
                cout << "Falha na validacao do endereco. Nao alterado.\n";
                esperar(2);
                continue;
            }

            bool ok = ms.editarHospede(email, "endereco", novoEndereco);
            if (ok) cout << "Endereco atualizado com sucesso!\n";
            else cout << "Erro ao atualizar no banco.\n";
            esperar(2);
        }
        else if (opcao == 2) {
            string novoCartao;
            cout << "Novo cartao:\n-> ";
            getline(cin, novoCartao);

            bool valido = ma.validarEditar(email, "", novoCartao);

            if (!valido) {
                cout << "Falha na validacao do cartao. Nao alterado.\n";
                esperar(2);
                continue;
            }

            bool ok = ms.editarHospede(email, "cartao", novoCartao);
            if (ok) cout << "Cartao atualizado com sucesso!\n";
            else cout << "Erro ao atualizar no banco.\n";
            esperar(2);
        }
        else if (opcao != 3) {
            cout << "Opcao invalida!\n";
            esperar(2);
        }

    } while (opcao != 3);

    cout << "Edicao concluida!\n";
    esperar(2);
}


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

//>>>>>>> c86f3e3ff28a09c902e478b180b0dc5ec4ae51e7
