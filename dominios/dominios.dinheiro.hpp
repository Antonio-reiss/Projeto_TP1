/**
* @file dominios.dinheiro.hpp
* @brief Definição da classe Dinheiro, responsável por armazenar valores monetários.
*
* O valor é armazenado como inteiro (centavos) para evitar erros de arredondamento.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef DOMINIOS_DINHEIRO_HPP_INCLUDED
#define DOMINIOS_DINHEIRO_HPP_INCLUDED
#include <string>

using namespace std;

/**
* @class Dinheiro
* @brief Representa e valida valores monetários no intervalo de 0,01 a 1.000.000,00.
* * Utiliza armazenamento em centavos (int) para garantir precisão.
*/
class Dinheiro{
private:
    int valorEmCentavos;
    /**
    * @brief Converte e valida uma string de entrada para o valor final em centavos.
    * @param valor string de entrada do usuário, como por exemplo, "1.000,00".
    * @return o valor total convertido para centavos (int).
    * @throws invalid_argument em caso de formato inválido ou valores fora do limite.
    */
    int validarConverter(string valor);
    /**
    * @brief Valida se o valor em centavos está dentro do intervalo de 1 a 1.000.000.000.
    * @param valor Valor em centavos.
    * @return true se o valor for válido, false caso contrário.
    */
    bool validar(int valor);
public:
    /**
    * @brief Construtor que inicializa o objeto com um valor double.
    * @param valor Valor numérico double a ser armazenado.
    * @throws invalid_argument se o valor estiver fora dos limites.
    */
    Dinheiro(double valor);
    /**
    * @brief Construtor que inicializa o objeto com uma string (entrada do usuário).
    * @param valor string de entrada, como por exemplo, "1.000,00".
    * @throws invalid_argument se o formato ou valor for inválido.
    */
    Dinheiro(string valor);
    /**
    * @brief Retorna o valor armazenado no formato decimal (double).
    * @return o valor monetário em reais, como por exemplo, 1000.00.
    */
    double getValor() const;
    /**
    * @brief Define e valida um novo valor monetário
    * @param valor Novo valor double a ser atribuído.
    * @throws invalid_argument se o valor estiver fora dos limites.
    */
    void setValor(double valor);
    /**
    * @brief Retorna o valor interno do objeto no formato de centavos (inteiro).
    * @return O valor armazenado como inteiro (centavos).
    */
    int getValorEmCentavos() const;
};

#endif // DOMINIOS_DINHEIRO_HPP_INCLUDED
