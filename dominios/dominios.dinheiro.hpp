/**
* @file dominios.dinheiro.hpp
<<<<<<< HEAD
* @brief Definição da classe Dinheiro, responsável por armazenar valores monetários.
*
* O valor é armazenado como inteiro (centavos) para evitar erros de arredondamento.
=======
* @brief Definição da classe Dinheiro.
*
* O valor é armazenado em centavos (inteiros) para evitar arrendodamentos e garantir precisão nos cálculos.
>>>>>>> a55cbb4104751007fab958247925110f55a55da9
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef DOMINIOS_DINHEIRO_HPP_INCLUDED
#define DOMINIOS_DINHEIRO_HPP_INCLUDED
#include <string>

using namespace std;

/**
<<<<<<< HEAD
* @class Dinheiro
* @brief Representa e valida valores monetários no intervalo de 0,01 a 1.000.000,00.
* * Utiliza armazenamento em centavos (int) para garantir precisão.
=======
* @class Endereco
* @brief Representa e valida um valor monetário no intervalo de 0,01 e 1.000.000,00.
*
* Armazena em centavos (int) para garantir precisão.
>>>>>>> a55cbb4104751007fab958247925110f55a55da9
*/
class Dinheiro{
private:
    int valorEmCentavos;
    /**
    * @brief Converte e valida uma stirng de entrada para o valor final em centavos.
    * @param valor String de entrada do usuário.
    * @return o valor total convertido para centavos (int).
    * @throws invalid_argument se o formato ou valor estiver fora do limite.
    */
    int validarConverter(string valor);
    /**
    * @brief valida se o valor em centavos está dentro do intervalo de 1 a 1000.000.000.
    * @param valor Valor em centavos.
    * @throws invalid_argument se o valor for inválido.
    */
    bool validar(int valor);
public:
    /**
    * @brief Construtor que inicializa o objeto com um valor double (uso programático).
    * @param valor Valor numérico double.
    * @throws invalid_argument se a validação falhar.
    */
    Dinheiro(double valor);
    /**
    * @brief Construtor que inicializa o objeto com uma string (entrada do usuário).
    * @param valor String de entrada no formato solicitado.
    * @throws invalid_argument se a validação falhar.
    */
    Dinheiro(string valor);
    /**
    * @brief Retorna o valor monetário armazenado no formato decimal (double) para exibição.
    * @return o valor monetário em reais.
    */
    double getValor() const;
    /**
    * @brief Define e valida um novo valor monetário a partir de um double.
    * @param valor Novo valor a ser atribuído.
    * @throws invalid_argument se a validação falhar.
    */
    void setValor(double valor);
    /**
    * @brief Retorna o valor interno do objeto no formato de centavos (inteiro).
    * @return O valor armazenado como inteiro (centavos).
    */
    int getValorEmCentavos() const;
};

#endif // DOMINIOS_DINHEIRO_HPP_INCLUDED
