/**
 * @file entidade.hotel.hpp
 * @brief Declaração da classe Hotel, que representa um hotel no sistema.
 *
 * Esta classe encapsula os dados principais de um hotel, incluindo seu nome,
 * endereço, telefone e código identificador. Cada atributo utiliza um domínio
 * específico (Nome, Endereco, Telefone, Codigo) para garantir consistência e
 * validação das informações armazenadas.
 *
 * Os métodos permitem acessar e modificar esses valores, sempre mantendo
 * a integridade definida pelas regras dos domínios.
 *
 * @author Ester Andrade Sousa - 242012109
 */
#ifndef ENTIDADES_HOTEL_HPP_INCLUDED
#define ENTIDADES_HOTEL_HPP_INCLUDED

#include "entidade.quarto.hpp"
#include "../dominios/dominios.codigo.hpp"
#include "../dominios/dominios.nome.hpp"
#include "../dominios/dominios.telefone.hpp"
#include "../dominios/dominios.endereco.hpp"

/**
 * @class Hotel
 * @brief Modelo que representa um hotel no sistema.
 *
 * A classe agrupa as informações fundamentais de um hotel, todas validadas
 * pelos respectivos domínios. É utilizada na camada de entidade para manter
 * dados organizados e seguros.
 */

class Hotel{
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;
public:
     /**
     * @brief Construtor completo da classe Hotel.
     *
     * Todos os parâmetros devem chegar previamente validados pelos domínios.
     *
     * @param nome Nome do hotel.
     * @param endereco Endereço do hotel.
     * @param telefone Telefone do hotel.
     * @param codigo Código identificador.
     */
    Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo);
     /**
     * @brief Define um novo nome para o hotel.
     * @param nome Objeto Nome já validado.
     */
    void setNome(const Nome& nome);
    /**
     * @brief Define um novo endereço para o hotel.
     * @param endereco Objeto Endereco já validado.
     */
    void setEndereco(const Endereco& endereco);
    /**
     * @brief Define um novo telefone para o hotel.
     * @param telefone Objeto Telefone já validado.
     */
    void setTelefone(const Telefone& telefone);
    /**
     * @brief Define um novo código identificador.
     * @param codigo Objeto Codigo já validado.
     */
    void setCodigo(const Codigo& codigo);
    /**
     * @brief Obtém o nome do hotel.
     * @return O nome atual.
     */

    Nome getNome() const;
    /**
     * @brief Obtém o endereço do hotel.
     * @return O endereço atual.
     */
    Endereco getEndereco() const;
     /**
     * @brief Obtém o telefone do hotel.
     * @return O telefone atual.
     */
    Telefone getTelefone() const;
     /**
     * @brief Obtém o código do hotel.
     * @return O código identificador.
     */
    Codigo getCodigo() const;
};


#endif // DOMINIOS_ENTIDADES_HOTEL_H_INCLUDED
