/**
* @file entidade.quarto.hpp
* @file entidade.quarto.hpp
* @brief Definicao da entidade Quarto.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef ENTIDADE_QUARTO_HPP_INCLUDED
#define ENTIDADE_QUARTO_HPP_INCLUDED

#include "../dominios/dominios.numero.hpp"
#include "../dominios/dominios.ramal.hpp"
#include "../dominios/dominios.dinheiro.hpp"
#include "../dominios/dominios.capacidade.hpp"

using namespace std;

/**
* @class Quarto
* @brief Entidade base que representa um Quarto no sistema.
*
* Contém objetos dos tipos, Numero, Capacidade, Dinheiro e Ramal, que valida e armazena os dados.
*/
class Quarto{
private:
    Numero numero;
    Capacidade capacidade;
    Dinheiro diaria;
    Ramal ramal;
public:
    /**
    * @brief Construtor da classe Quarto.
    * @param numero Inteiro com o numero inicial a ser validado pelo dominio Numero.
    * @param capacidade Inteiro com a capacidade inicial a ser validada pelo dominio Capacidade.
    * @param diaria String com o diaria inicial a ser validada pelo dominio Dinheiro.
    * @param ramal Inteiro com o ramal inicial a ser validado pelo dominio Ramal.
    */
    Quarto(const int& numero, const int& capacidade, const string& diaria, const int& ramal);
    /**
    * @brief Define e valida um novo numero para o objeto, delegando a validacao ao dominio Numero.
    * @param numero o novo numero a ser validado.
    */
    void setNumero(int numero);
    /**
    * @brief Define e valida uma nova capacidade para o objeto, delegando a validacao ao dominio Capacidade.
    * @param capacidade uma capacidade a ser validada.
    */
    void setCapacidade(int capacidade);
    /**
    * @brief Define e valida uma nova diaria para o objeto, delegando a validacao ao dominio Dinheiro.
    * @param diaria String de diaria a ser validada.
    */
    void setDiaria(const string& diaria);
    /**
    * @brief Define e valida um novo ramal para o objeto, delegando a validacao ao dominio Ramal.
    * @param Um ramal inteiro a ser validado.
    */
    void setRamal(int ramal);
    /**
    * @brief Retorna o numero do quarto.
    * @return O numero inteiro do quarto.
    */
    int getNumero() const;
    /**
    * @brief Retorna a capacidade do quarto.
    * @return A capacidade inteira do quarto.
    */
    int getCapacidade() const;
    /**
    * @brief Retorna a string diaria do quarto.
    * @return O valor da diaria.
    */
    double getDiaria() const;
    /**
    * @brief Retorna o ramal do quarto.
    * @return O número do ramal.
    */
    int getRamal() const;
};

#endif // ENTIDADE_QUARTO_HPP_INCLUDED
