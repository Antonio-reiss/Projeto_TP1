/**
* @file dominios.dinheiro.hpp
* @brief Definicao da classe Dinheiro, responsavel por armazenar valores monetarios.
*
* O valor eh armazenado como inteiro (centavos) para evitar erros de arredondamento.
* @brief Definicao da classe Dinheiro.
*
* O valor eh armazenado em centavos (inteiros) para evitar arrendodamentos e garantir precisao nos calculos.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef DOMINIOS_DINHEIRO_HPP_INCLUDED
#define DOMINIOS_DINHEIRO_HPP_INCLUDED
#include <string>

using namespace std;

/**
* @class Dinheiro
* @brief Representa e valida valores monetarios no intervalo de 0,01 a 1.000.000,00.
*
* * Utiliza armazenamento em centavos (int) para garantir precisao.
* @class Endereco
* @brief Representa e valida um valor monetario no intervalo de 0,01 e 1.000.000,00.
*
* Armazena em centavos (int) para garantir precisao.
*/
class Dinheiro{
private:
    int valorEmCentavos;
    /**
    * @brief Converte e valida uma stirng de entrada para o valor final em centavos.
    * @param valor String de entrada do usuario.
    * @return o valor total convertido para centavos (int).
    * @throws invalid_argument se o formato ou valor estiver fora do limite.
    */
    int validarConverter(string valor);
    /**
    * @brief valida se o valor em centavos esta dentro do intervalo de 1 a 1000.000.000.
    * @param valor Valor em centavos.
    * @throws invalid_argument se o valor for invalido.
    */
    bool validar(int valor);
public:
    /**
    * @brief Construtor que inicializa o objeto com um valor double (uso programatico).
    * @param valor Valor numerico double.
    * @throws invalid_argument se a validacao falhar.
    */
    Dinheiro(double valor);
    /**
    * @brief Construtor que inicializa o objeto com uma string (entrada do usuario).
    * @param valor String de entrada no formato solicitado.
    * @throws invalid_argument se a validacao falhar.
    */
    Dinheiro(string valor);
    /**
    * @brief Retorna o valor monetario armazenado no formato decimal (double) para exibicao.
    * @return o valor monetario em reais.
    */
    double getValor() const;
    /**
    * @brief Define e valida um novo valor monetario a partir de um double.
    * @param valor Novo valor a ser atribuido.
    * @throws invalid_argument se a validacao falhar.
    */
    void setValor(double valor);
    /**
    * @brief Retorna o valor interno do objeto no formato de centavos (inteiro).
    * @return O valor armazenado como inteiro (centavos).
    */
    int getValorEmCentavos() const;
};

#endif // DOMINIOS_DINHEIRO_HPP_INCLUDED
