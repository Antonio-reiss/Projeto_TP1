/**
* @file dominios.numero.hpp
* @brief Definicao da classe Numero, que representa e valida numeros inteiros dentro de um limite.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef DOMINIOS_NUMERO_HPP_INCLUDED
#define DOMINIOS_NUMERO_HPP_INCLUDED

/**
* @class Numero
* @brief Representa e valida um ramal no intervalo de 1 a 999.
*/
class Numero{
private:
    int numero;
    static const int MAX_VALOR = 999;
    static const int MIN_VALOR = 1;
    /**
    * @brief Verifica se o valor numerico esta dentro do intervalo permitido.
    * @param numero eh o valor numerico a ser validado.
    * @return true se o valor for valido, caso contrario, lanca excecao.
    * @throws invalid_argument se o numero estiver fora do intervalo.
    */
    bool validar_numero(int);
public:
    /**
    * @brief Construtor da classe Numero.
    * @param numero eh o valor numerico inicial.
    */
    Numero(int);
    /**
    * @brief Define e valida um novo numero.
    * @param numero eh o valor numerico inicial.
    */
    void setNumero(int);
    /**
    * @brief Retorna o numero armazenado no objeto.
    * @return O valor numerico inteiro.
    */
    int getNumero() const;
};

#endif // DOMINIOS_NUMERO_HPP_INCLUDED
