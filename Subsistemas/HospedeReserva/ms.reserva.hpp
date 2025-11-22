/**
 * @file ms.reserva.hpp
 * @brief Implementacao concreta do modulo de servico de Reserva.
 *
 * Realiza operacoes de CRUD sobre reservas, utilizando regras de negocio,
 * integracao com o banco de dados e validacao por meio das classes dominio.
 * @author Ester Andrade Sousa - 242012109
 */

#ifndef MS_RESERVA_HPP_INCLUDED
#define MS_RESERVA_HPP_INCLUDED

#include "is.reserva.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"
#include "../../entidades/entidade.reserva.hpp"
#include "../../dominios/dominios.codigo.hpp"
#include "../../dominios/dominios.data.hpp"
#include "../../dominios/dominios.dinheiro.hpp"
#include "../../dominios/dominios.email.hpp"

/**
 * @class msReserva
 * @brief Servico responsavel por manipular reservas no sistema.
 *
 * Esta classe implementa a interface isReserva e aplica as regras de negocio
 * necessarias para garantir consistencia, evitar conflitos de datas e validar
 * os dados por meio das classes dominio.
 */
class msReserva : public isReserva {

private:
    /**
     * @brief Instancia do banco de dados utilizada para persistir e consultar reservas.
     */
    bancoDeDados db;

public:

    /**
     * @brief Cria uma nova reserva no sistema.
     *
     * @details O metodo realiza validaçcao dos dominios (Codigo, Email, Data, Dinheiro),
     * verifica disponibilidade e, se tudo estiver correto, armazena a reserva no banco.
     *
     * @param string codigo identificador único da reserva.
     * @param string email email associado à reserva.
     * @param string dataInicio data de início da estadia.
     * @param string dataFim data final da estadia.
     * @param string valor total da reserva.
     * @param int numeroQuarto número do quarto reservado.
     *
     * @return true se a operacao for concluida com sucesso, false caso contrario.
     */
    bool criarReserva(const string&, const string&, const string&, const string&, const string&, int) override;

    /**
     * @brief Lista todas as reservas cadastradas no sistema.
     *
     * @details Recupera os registros armazenados no banco e exibe em formato legivel.
     *
     * @return true se a listagem ocorrer corretamente, false em caso de falha.
     */
    bool listarReservas() override;

    /**
     * @brief Edita os dados de uma reserva ja existente.
     *
     * @param string codigo código identificador da reserva que sera modificada.
     * @param string campo nome do campo que sera atualizado.
     * @param string novoDado valor atualizado.
     *
     * @return true se a edicao for bem-sucedida, false caso contrario.
     */
    bool editarReserva(string, string, string) override;

    /**
     * @brief Exclui uma reserva com base no código identificador.
     *
     * @param string codigo codigo da reserva a ser removida.
     *
     * @return true se a exclusao ocorrer corretamente, false em falhas.
     */
    bool excluirReserva(const string&) override;

};

#endif // MS_RESERVA_HPP_INCLUDED
