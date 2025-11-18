/**
* @file dominios.capacidade.hpp
* @brief Definicao da classe Capacidade, que valida a capacidade de um quarto.
*
* @author Ester Andrade Sousa - 242012109
*/
#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include<stdexcept>

using namespace std;

/**
* @class Capacidade
* @brief Representa e valida a capacidade de um quarto (1 a 4 hospedes).
*/
class Capacidade {
private:
    int valor;
public:
    /**
    * @brief Construtor da classe Capacidade.
    * @param valor Inteiro representando a capacidade inicial.
    * @throws invalid_argument se a capacidade for invalida.
    */
    Capacidade (int valor);
/**
    * @brief Define e valida um novo valor para a capacidade.
    * @param valor Novo valor entre 1 e 4.
    * @throws invalid_argument se o valor estiver fora do intervalo.
    */
    void setValor (int valor);
 /**
    * @brief Retorna o valor da capacidade.
    * @return Valor inteiro da capacidade.
    */
    int getValor () const;


};


#endif // DOMINIOS_HPP_INCLUDED
