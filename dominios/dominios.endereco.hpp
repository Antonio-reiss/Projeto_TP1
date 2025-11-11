/**
* @file dominios.endereco.hpp
* @brief Definição da classe Endereco, que representa e valida um endereço.
*
* O domínio Endereço segue regras de limites de caracteres e restrições
* no uso de pontuações e espaços.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef DOMINIOS_ENDERECO_HPP_INCLUDED
#define DOMINIOS_ENDERECO_HPP_INCLUDED
#include <string>
using namespace std;

/**
* @class Endereco
* @brief Representa e valida um endereço de rua.
*
* Garaante que o endereço tenha entre 5 e 30 caracteres, use apenas
* alfanuméricos, espaços, vírgulas e pontos, e não contenha espaços ou
* pontuações consecutivas ou nas extremidades.
*/
class Endereco{
private:
    string endereco;
   void validar(string endereco);
public:
    Endereco(string endereco);
    string getEndereco() const;
    void setEndereco(string endereco);
};

#endif // DOMINIOS_ENDERECO_HPP_INCLUDED
