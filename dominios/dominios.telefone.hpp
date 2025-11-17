/**
* @file dominios.telefone.hpp
* @brief Definicao da classe Telefone, que representa e valida um numero de telefone.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef DOMINIOS_TELEFONE_HPP_INCLUDED
#define DOMINIOS_TELEFONE_HPP_INCLUDED
#include <string>
using namespace std;

/**
* @class Telefone
* @brief Representa e valida um numero de telefone.
* @details O telefone eh possui o formato +DDDDDDDDDDDDDD, onde D sao digitos (0-9).
*/
class Telefone{
private:
    string telefone;
    /**
    * @brief Verifica se string do atende ao formato e tamanho exigidos ( + e 13 digitos).
    * @param telefone eh a string do telefone a ser validada.
    * @return true se o telefone for valido, caso contrario, lanca excecao.
    * @throws invalid_argument se o formato ou tamanho for incorreto.
    */
    bool validar_telefone(string&);
public:
    /**
     * @brief Construtor da classe Telefone.
     * @param telefone eh a string com o numero de telefone inicial.
     */
    Telefone(string);
    /**
     * @brief Define e valida um novo numero de telefone, formatando-o.
     * @param telefone eh a nova string do numero de telefone.
     */
    void setTelefone(string&);
    /**
     * @brief Retorna o numero de telefone formatado armazenado.
     * @return A string do telefone.
     */
    string getTelefone() const;

};

#endif // DOMINIOS_TELEFONE_HPP_INCLUDED
