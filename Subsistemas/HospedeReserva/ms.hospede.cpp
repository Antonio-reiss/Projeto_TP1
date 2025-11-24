/**
 * @file ms.hospede.cpp
 * @brief Implementacao dos metodos de servico da classe msHospede.
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
        esperar(5);
        return true;
    }
    catch (...) {
        cout << "Erro ao listar hospedes.\n";
        esperar(5);
        return false;
    }
}

bool msHospede::editarHospede(string codigo, string campo, string novoValor)
{
    try {
/*<<<<<<< HEAD
        Hospede hospedeTemporario("nomee", "email", "ender,", "1234123412341234");

        db.montarHospede(hospedeTemporario);

=======
        // valida apenas o campo que está sendo alterado
>>>>>>> c86f3e3ff28a09c902e478b180b0dc5ec4ae51e7*/
        if (campo == "nome") {
            Nome n(novoValor);             // valida nome
        }
        else if (campo == "email") {
            Email e(novoValor);           // valida email
        }
        else if (campo == "endereco") {
            Endereco end(novoValor);     // valida endereco
        }
        else if (campo == "cartao") {
            Cartao c(novoValor);
        }
        else {
            throw invalid_argument("Campo invalido para edicao.");
        }

        if (!db.editarHospedeCampo(codigo, campo, novoValor)) {
            cout << "Erro ao atualizar no banco." << endl;
            return false;
        }

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
    return true;
}
