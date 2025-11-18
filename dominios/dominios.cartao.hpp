/**
* @file dominios.cartao.hpp
* @brief Definicao da classe Cartao, que representa um numero de cartao validado pelo algoritmo de Luhn.
*
* @author Ester Andrade Sousa - 242012109
*/
#ifndef DOMINIOS_CARTAO_HPP_INCLUDED
#define DOMINIOS_CARTAO_HPP_INCLUDED

#include <string>

using namespace std;
/**
* @class Cartao
* @brief Representa e valida um numero de cartao de 16 digitos com algoritmo de Luhn.
*/

class Cartao{
private:
    string valor;
/**
    * @brief Verifica se o numero do cartao e valido pelo algoritmo de Luhn.
    * @param num Numero do cartao como string.
    * @return true se o cartao for valido; caso contrario, false.
    */
    bool validarLuhn (const string &num) const;
public:
/**
    * @brief Construtor da classe Cartao.
    * @param valor Numero inicial do cartao em formato string.
    * @throws invalid_argument se o valor nao for valido.
    */
    Cartao(string valor);
/**
    * @brief Define e valida um novo numero de cartao.
    * @param valor Numero do cartao como string de 16 digitos.
    * @throws invalid_argument se o valor nao for valido.
    */
    void setValor(string valor);
/**
    * @brief Retorna o valor do cartao.
    * @return String contendo o numero do cartao.
    */
    string getValor() const;

};

#endif // DOMINIOS_CARTAO_H_INCLUDED
