/**
 * @file ms.hospede.cpp
 * @brief Implementacao dos metodos de serviço da classe msHospede.
 * @author Ester Andrade Sousa - 242012109
 */

#include "ms.hospede.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;


bool msHospede::criarHospede(const string& nome,
                             const string& email,
                             const string& endereco,
                             const string& cartao)
{
    try {
        Hospede novo(nome, email, endereco, cartao);

        return db.criarHospede(novo);
    }
    catch (const exception& e) {
        cout << "Erro ao criar hospede: " << e.what() << endl;
        return false;
    }
}

bool msHospede::listarHospedes()
{
    try {
        db.listarTodos("HOSPEDE");
        return true;
    }
    catch (...) {
        cout << "Erro ao listar hospedes.\n";
        return false;
    }
}
bool msHospede::editarHospede(string codigo,
                              string campo,
                              string novoValor)
{
    try {
        Hospede hospedeTemporario("nome", "email", "ender,", "1234123412341234");

        db.montarHospede(hospedeTemporario);

        if (campo == "nome") {
            hospedeTemporario.setNome(novoValor);
        }
        else if (campo == "email") {
            hospedeTemporario.setEmail(novoValor);
        }
        else if (campo == "endereco") {
            hospedeTemporario.setEndereco(novoValor);
        }
        else if (campo == "cartao") {
            hospedeTemporario.setCartao(novoValor);
        }
        else {
            throw invalid_argument("Campo invalido para edicao.");
        }

        db.editarHospede(hospedeTemporario, codigo);
        return true;
    }
    catch (const exception& e) {
        cout << "Erro ao editar hospede: " << e.what() << endl;
        return false;
    }
}

bool msHospede::excluirHospede(const string& codigo)
{
    try {
        db.apagarUm("HOSPEDE", "CODIGO", codigo);
        return true;
    }
    catch (...) {
        cout << "Erro ao excluir hospede.\n";
        return false;
    }
}
