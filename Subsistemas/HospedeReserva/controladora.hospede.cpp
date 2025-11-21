/**
 * @file controladora.hospede.cpp
 * @brief Implementação da controladora de hóspedes.
 *
 * Contém as funções que fazem a ponte entre a camada de apresentação
 * e o módulo de serviço de hóspedes (msHospede). Todas as operações
 * de CRUD são delegadas ao serviço e mensagens de status são exibidas
 * no console.
 * @author Ester Andrade Sousa - 242012109
 */

#include "controladora.hospede.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Construtor da controladora de hóspedes.
 *
 * @details Inicializa a instância do módulo de serviço (msHospede).
 */
controladoraHospede::controladoraHospede() {
    ms = new msHospede();
}

/**
 * @brief Destrutor da controladora de hóspedes.
 *
 * @details Libera os recursos alocados para o módulo de serviço.
 */
controladoraHospede::~controladoraHospede() {
    delete ms;
}

/**
 * @brief Cria um novo hóspede.
 *
 * @param nome Nome do hóspede.
 * @param email Email do hóspede.
 * @param endereco Endereço do hóspede.
 * @param cartao Cartão do hóspede.
 *
 * @return true se a criação ocorrer com sucesso, false caso contrário.
 */
bool controladoraHospede::criarHospede(const string& nome,
                                       const string& email,
                                       const string& endereco,
                                       const string& cartao)
{
    bool ok = ms->criarHospede(nome, email, endereco, cartao);

    if (!ok) {
        cout << "Falha ao criar hóspede." << endl;
        return false;
    }

    cout << "Hóspede criado com sucesso!" << endl;
    return true;
}

/**
 * @brief Lista todos os hóspedes cadastrados.
 *
 * @return true se a listagem ocorrer corretamente, false em caso de falha.
 */
bool controladoraHospede::listarHospedes() {
    bool ok = ms->listarHospedes();

    if (!ok) {
        cout << "Falha ao listar hóspedes." << endl;
        return false;
    }

    return true;
}

/**
 * @brief Edita os dados de um hóspede existente.
 *
 * @param email Email do hóspede que será editado.
 * @param novoEndereco Novo endereço.
 * @param novoCartao Novo cartão.
 *
 * @return true se a edição for bem-sucedida, false caso contrário.
 */
bool controladoraHospede::editarHospede(const string& email,
                                        const string& novoEndereco,
                                        const string& novoCartao)
{
    bool ok = ms->editarHospede(email, novoEndereco, novoCartao);

    if (!ok) {
        cout << "Falha ao editar hóspede." << endl;
        return false;
    }

    cout << "Hóspede atualizado com sucesso!" << endl;
    return true;
}

/**
 * @brief Exclui um hóspede pelo email.
 *
 * @param email Email do hóspede que será removido.
 *
 * @return true se a exclusão ocorrer com sucesso, false em caso de falha.
 */
bool controladoraHospede::excluirHospede(const string& email)
{
    bool ok = ms->excluirHospede(email);

    if (!ok) {
        cout << "Falha ao excluir hóspede." << endl;
        return false;
    }

    cout << "Hóspede excluído com sucesso!" << endl;
    return true;
}
