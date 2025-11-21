/**
 * @file ms.hospede.hpp
 * @brief Implementação concreta do módulo de serviço do Hóspede.
 *
 * Esta classe faz a ponte entre a lógica de aplicação e o banco de dados,
 * permitindo criação, edição, listagem e exclusão de hóspedes.
 * @author Ester Andrade Sousa - 242012109
 */


#ifndef MS_HOSPEDE_HPP_INCLUDED
#define MS_HOSPEDE_HPP_INCLUDED

#include "is.hospede.hpp"
#include "subsistemas/BancoDados/bancoDeDados.hpp"
#include "subsistemas/funcoes.de.controles.hpp"

#include "entidades/entidade.hospede.hpp"
#include "dominios/dominios.nome.hpp"
#include "dominios/dominios.email.hpp"
#include "dominios/dominios.endereco.hpp"
#include "dominios/dominios.cartao.hpp"

/**
 * @class msHospede
 * @brief Serviço de gerenciamento de hóspedes com integração ao banco de dados.
 *
 * A classe implementa a interface isHospede e utiliza o subsistema bancoDeDados
 * para executar as operações de armazenamento e consulta.
 */
class msHospede : public isHospede {

private:
/**
     * @brief Instância do banco de dados utilizada para persistência.
     */
    bancoDeDados db;

public:
/**
     * @brief Cria um novo hóspede no sistema.
     * @details Valida os domínios (Nome, Email, Endereco, Cartao) antes de persistir no banco.
     *
     * @param string nome do hóspede.
     * @param string email do hóspede.
     * @param string endereco do hóspede.
     * @param string cartao associado.
     * @return true se a criação for concluída com sucesso, false caso contrário.
     */

    bool criarHospede(const string&, const string&, const string&, const string&) override;
/**
     * @brief Lista todos os hóspedes cadastrados.
     * @details Recupera e exibe os registros armazenados no banco de dados.
     *
     * @return true se a operação ocorrer corretamente, false se houver falha.
     */
    bool listarHospedes() override;
 /**
     * @brief Edita os dados de um hóspede existente.
     *
     * @param string email do hóspede a ser alterado.
     * @param string campo nome do campo que será editado.
     * @param string novoDado valor atualizado a ser gravado.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool editarHospede(string, string, string) override;

   /**
     * @brief Exclui um hóspede com base no nome.
     *
     * @param string nome do hóspede a ser excluído.
     * @return true se a exclusão for concluída, false caso contrário.
     */
    bool excluirHospede(const string&) override;

};

#endif // MS_HOSPEDE_HPP_INCLUDED
