/**
 * @file ma.hospede.cpp
 * @brief Implementacao das regras de validacao para criacao, edicao e exclusao de hospedes.
 * @author Ester Andrade Sousa - 242012109
 */

#include "ma.hospede.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

bool MAHospede::validarCriar(string& nome, string& email, string& endereco, string& cartao) {
    try {
        Nome nomeValido(nome);
        Email emailValido(email);
        Endereco enderecoValido(endereco);
        Cartao cartaoValido(cartao);
    }
    catch (const exception& e) {
        cout << "Erro ao validar hóspede: " << e.what() << endl;
        return false;
    }
    cout << "Hóspede criado com sucesso!" << endl;
    return true;
}

bool MAHospede::validarEditar(string& email, string& endereco, string& cartao) {
    try {
        Email emailValido(email);
        Endereco enderecoValido(endereco);
        Cartao cartaoValido(cartao);
    }
    catch (const exception& e) {
        cout << "Erro ao editar hóspede. " << e.what() << endl;
        return false;
    }
    cout << "Dados do hóspede atualizados com sucesso!" << endl;
    return true;
}

bool MAHospede::validarExcluir(string& email) {
    try {
        Email emailValido(email);
    }
    catch (const exception& e) {
        cout << "Erro ao excluir hóspede. " << e.what() << endl;
        return false;
    }
    cout << "Hóspede excluído com sucesso!" << endl;
    return true;
}
