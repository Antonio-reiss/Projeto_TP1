/**
 * @file ms.hospede.cpp
 * @brief Implementação dos métodos de serviço da classe msHospede.
 *
 * Contém as operações de criação, listagem, edição e exclusão de hóspedes,
 * com validação por domínios e integração direta com o banco de dados.
 * @author Ester Andrade Sousa - 242012109
 */

#include "ms.hospede.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @brief Cria um novo hóspede no sistema.
 *
 * @details O método instancia um objeto Hospede utilizando os domínios
 * (Nome, Email, Endereco, Cartao). Caso algum domínio seja inválido,
 * uma exceção é lançada e tratada, garantindo que o sistema não quebre.
 *
 * @param nome nome do hóspede.
 * @param email email do hóspede.
 * @param endereco endereço do hóspede.
 * @param cartao número do cartão associado.
 *
 * @return true se o hóspede for criado com sucesso, false se ocorrer erro.
 */
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
        cout << "Erro ao criar hóspede: " << e.what() << endl;
        return false;
    }
}

/**
 * @brief Lista todos os hóspedes cadastrados.
 *
 * @details Solicita ao banco de dados a listagem completa da tabela HOSPEDE.
 * Exceções genéricas são tratadas para evitar interrupção do fluxo.
 *
 * @return true se a listagem ocorrer sem erros, false caso contrário.
 */
bool msHospede::listarHospedes()
{
    try {
        db.listarTodos("HOSPEDE");
        return true;
    }
    catch (...) {
        cout << "Erro ao listar hóspedes.\n";
        return false;
    }
}

/**
 * @brief Edita informações de um hóspede já existente.
 *
 * @details O método monta um objeto temporário com dados do banco,
 * aplica a modificação desejada no campo informado e persiste a alteração.
 * Validações de domínio são aplicadas automaticamente pelos setters.
 *
 * @param codigo identificador do hóspede no banco.
 * @param campo nome do campo a ser alterado (nome, email, endereco, cartao).
 * @param novoValor valor atualizado a ser aplicado.
 *
 * @return true se a edição for bem-sucedida, false em caso de erro.
 */
bool msHospede::editarHospede(string codigo,
                              string campo,
                              string novoValor)
{
    try {
      // Instância temporária apenas para receber valores do banco
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
            throw invalid_argument("Campo inválido para edição.");
        }

        db.editarHospede(hospedeTemporario, codigo);
        return true;
    }
    catch (const exception& e) {
        cout << "Erro ao editar hóspede: " << e.what() << endl;
        return false;
    }
}

/**
 * @brief Exclui um hóspede do sistema com base no código.
 *
 * @details A remoção é feita diretamente no banco de dados.
 * Caso ocorra falha, uma exceção genérica é capturada.
 *
 * @param codigo código do hóspede que será removido.
 *
 * @return true se a exclusão ocorrer normalmente, false em erro.
 */
bool msHospede::excluirHospede(const string& codigo)
{
    try {
        db.apagarUm("HOSPEDE", "CODIGO", codigo);
        return true;
    }
    catch (...) {
        cout << "Erro ao excluir hóspede.\n";
        return false;
    }
}
