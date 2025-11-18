/**
* @file dominios.data.hpp
* @brief Definicao da classe Data, que representa e valida uma data no formato dia-mes-ano.
*
* @author Ester Andrade Sousa - 242012109
*/

#ifndef DOMINIOS_DATA_HPP_INCLUDED
#define DOMINIOS_DATA_HPP_INCLUDED
#include <string>

using namespace std;
/**
* @class Data
* @brief Representa e valida uma data no formato dd-MES-aaaa.
*/

class Data{
private:
    int dia;
    string mes;
    int ano;
 /**
    * @brief Verifica se a data fornecida e valida.
    * @param dia Dia numerico (1 a 31).
    * @param mes Nome do mes abreviado.
    * @param ano Ano numerico.
    * @return true se a data for valida, false caso contrario.
    */
    bool validar (int dia, string mes, int ano) const;
public:
 /**
    * @brief Construtor da classe Data.
    * @param dia Dia inicial.
    * @param mes Mes inicial em formato abreviado (ex: JAN).
    * @param ano Ano inicial.
    * @throws invalid_argument se a data nao for valida.
    */
    Data(int dia, string mes, int ano);
 /**
    * @brief Define e valida um novo valor de data.
    * @param dia Dia numerico.
    * @param mes Mes abreviado.
    * @param ano Ano.
    * @throws invalid_argument se a data nao for valida.
    */
    void setValor (int dia, string mes, int ano);
    /// @brief Retorna o dia da data.\n @return Inteiro entre 1 e 31.
    int getDia() const;
    /// @brief Retorna o mes abreviado da data.\n @return String com o mes (ex: JAN).
    string getMes() const;
    /// @brief Retorna o ano da data.\n @return Inteiro.
    int getAno() const;
    /// @brief Retorna a data completa como string no formato "dia-mes-ano".\n @return String com a data formatada.
    string getValor() const;
};


#endif // DOMINIOS_DATA_HPP_INCLUDED
