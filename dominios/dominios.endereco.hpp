/**
* @file dominios.endereco.hpp
* @brief Definicao da classe Endereco, que representa e valida um endereco.
*
* O dominio Endereco segue regras de limites de caracteres e restricoes
* no uso de pontuacoes e espacos.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef DOMINIOS_ENDERECO_HPP_INCLUDED
#define DOMINIOS_ENDERECO_HPP_INCLUDED
#include <string>
using namespace std;

/**
* @class Endereco
* @brief Representa e valida um endereco de rua.
*
* Garaante que o endereco tenha entre 5 e 30 caracteres, use apenas
* Garante que o endereco tenha entre 5 e 30 caracteres, use apenas
* alfanuméricos, espacos, virgulas e pontos, e nao contenha espacos ou
* pontuacoes consecutivas ou nas extremidades.
*/
class Endereco{
private:
    string endereco;
    /**
    * @brief Verifica se a string de endereco atende aos requisitos.
    * @param endereco Em string contendo o endereco a ser validado.
    * @throws invalid_argument se o tamanho ou formato for invalido.
    */
    bool validar(string endereco);
public:
    /**
    * @brief construtor da classe Endereco.
    * @param endreco string com o endereco inicial.
    * @throws invalid_argument se a validacao falhar.
    */
    Endereco(string endereco);
    /**
    * @brief Retorna o endereco armazenado no objeto.
    * @return A string do endereco validado.
    */
    string getEndereco() const;
    /**
    * @brief Define e valida um novo endereco para o objeto.
    * @param endereco Contendo a nova string  se o endereco for valido.
    */
    void setEndereco(string endereco);
};

#endif // DOMINIOS_ENDERECO_HPP_INCLUDED
