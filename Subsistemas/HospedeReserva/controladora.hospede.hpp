/**
 * @file controladora.hospede.hpp
 * @brief Controladora da camada de controle para hóspedes.
 *
 * Atua como intermediária entre a camada de apresentação e o serviço de hóspedes (isHospede / msHospede),
 * delegando operações de criação, listagem, edição e exclusão.
 *@author Ester Andrade Sousa - 242012109
 */

#ifndef CONTROLADORA_HOSPEDE_HPP_INCLUDED
#define CONTROLADORA_HOSPEDE_HPP_INCLUDED

#include "is.hospede.hpp"
#include "ms.hospede.hpp"
#include <string>

/**
 * @class controladoraHospede
 * @brief Controladora de hóspedes.
 *
 * Implementa métodos que utilizam o módulo de serviço de hóspedes para realizar
 * operações de CRUD, garantindo que a camada de apresentação não acesse
 * diretamente o serviço.
 */
class controladoraHospede {
private:
    /**
     * @brief Ponteiro para o módulo de serviço de hóspedes.
     */
    isHospede* ms;

public:
    /**
     * @brief Construtor da controladora.
     *
     * Inicializa o ponteiro para o módulo de serviço (msHospede).
     */
    controladoraHospede();

    /**
     * @brief Destrutor da controladora.
     *
     * Libera recursos alocados e garante destruição correta do serviço.
     */
    ~controladoraHospede();

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
    bool criarHospede(const std::string&, const std::string&, const std::string&, const std::string&);

    /**
     * @brief Lista todos os hóspedes cadastrados.
     *
     * @return true se a listagem ocorrer corretamente, false em caso de erro.
     */
    bool listarHospedes();

    /**
     * @brief Edita os dados de um hóspede existente.
     *
     * @param emailChave Email do hóspede a ser editado.
     * @param novoEndereco Novo endereço.
     * @param novoCartao Novo cartão.
     *
     * @return true se a edição for bem-sucedida, false caso contrário.
     */
    bool editarHospede(const std::string&, const std::string&, const std::string&);

    /**
     * @brief Exclui um hóspede pelo email.
     *
     * @param email Email do hóspede que será removido.
     *
     * @return true se a exclusão ocorrer com sucesso, false em caso de falha.
     */
    bool excluirHospede(const std::string&);
};

#endif // CONTROLADORA_HOSPEDE_HPP_INCLUDED
