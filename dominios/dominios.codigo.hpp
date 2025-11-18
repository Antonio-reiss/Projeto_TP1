/**
* @file dominios.codigo.hpp
* @brief Definicao da classe Codigo, que representa um codigo alfanumerico de 10 caracteres.
*
* @author Ester Andrade Sousa - 242012109
*/

#ifndef DOMINIOS_CODIGO_HPP_INCLUDED
#define DOMINIOS_CODIGO_HPP_INCLUDED
#include<string>
using namespace std;
/**
* @class Codigo
* @brief Representa e valida um codigo de 10 caracteres contendo letras minusculas e numeros.
*/

class Codigo{
private:
    string valor;
public:
/**
    * @brief Construtor da classe Codigo.
    * @param valor Valor inicial do codigo em string.
    * @throws invalid_argument se o valor nao for valido.
    */
    Codigo(string valor);
/**
    * @brief Define e valida um novo codigo.
    * @param valor Novo valor do codigo.
    * @throws invalid_argument se o codigo nao for valido.
    */
    void setValor (string valor);
/**
    * @brief Retorna o codigo armazenado.
    * @return String com o valor do codigo.
    */
    string getValor() const;

};

#endif // DOMINIOS_CODIGO_HPP_INCLUDED
