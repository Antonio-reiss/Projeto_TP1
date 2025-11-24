/**
 * @file ma.hospede.cpp
 * @brief Implementacao das regras de validacao para criacao, edicao e exclusao de hospedes.
 * @author Ester Andrade Sousa - 242012109
 */

#include "ma.hospede.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

bool MAHospede::validarCriar(const string& nome, const string& email, const string& endereco, const string& cartao) {
    try {
        Nome nomeValido(nome);
        Email emailValido(email);
        Endereco enderecoValido(endereco);
        Cartao cartaoValido(cartao);
    }
    catch (const exception& e) {
        cout << "Erro ao validar hospede: " << e.what() << endl;
        return false;
    }
    cout << "Hospede criado com sucesso!" << endl;
    return true;
}


bool MAHospede::validarEditar(const string& email,
                              const string& endereco,
                              const string& cartao) {
    try {
        Email emailValido(email);

        if (!endereco.empty()) {
            Endereco enderecoValido(endereco);
        }

        if (!cartao.empty()) {
            Cartao cartaoValido(cartao);
        }
    }
    catch (const exception& e) {
        cout << "Erro ao editar hospede. " << e.what() << endl;
        return false;
    }

    return true; // sem mensagem aqui
}



bool MAHospede::validarExcluir(const string& email) {
    try {
        Email emailValido(email);
    }
    catch (const exception& e) {
        cout << "Erro ao excluir hospede. " << e.what() << endl;
        return false;
    }

    return true;
}
