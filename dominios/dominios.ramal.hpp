/**
* @file dominios.ramal.hpp
* @brief Definicao da classe Ramal, que representa e valida um numero de ramal inteiro.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef DOMINIOS_RAMAL_HPP_INCLUDED
#define DOMINIOS_RAMAL_HPP_INCLUDED

/**
* @class Ramal
* @brief Representa um ramal num intervalo de 0 a 50.
*/
class Ramal{
private:
    int ramal;
    static const int MAX_RAMAL = 50;
    static const int MIN_RAMAL = 0;
    /**
    * @brief Verifica se o valor do ramal esta dentro do intervalo permitido (0 a 50).
    * @param ramal eh o valor do ramal a ser validado.
    * @return true se o ramal for valido, caso contrario, lanca excecao.
    * @throws invalid_argument se o valor estiver fora do intervalo.
    */
    bool validar_ramal(int);
public:
    /**
    * @brief Construtor da classe ramal.
    * @param ramal com o valor inteiro inicial.
    */
    Ramal(int);
    /**
    * @brief Define e valida um novo numero de ramal.
    * @param ramal com o novo valor inteiro.
    */
    void setRamal(int);
    /**
    * @brief Retorna o numero de ramal armazenado.
    * @return O valor do ramal armazenando (int).
    */
    int getRamal() const;

};

#endif // DOMINIOS_RAMAL_HPP_INCLUDED
