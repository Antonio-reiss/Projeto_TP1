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
<<<<<<< HEAD
* Garaante que o endereço tenha entre 5 e 30 caracteres, use apenas
=======
* Garante que o endereço tenha entre 5 e 30 caracteres, use apenas
>>>>>>> a55cbb4104751007fab958247925110f55a55da9
* alfanuméricos, espaços, vírgulas e pontos, e não contenha espaços ou
* pontuações consecutivas ou nas extremidades.
*/
class Endereco{
private:
    string endereco;
    /**
    * @brief Verifica se a string de endereco atende aos requisitos.
    * @param endereco Em string contendo o endereço a ser validado.
    * @throws invalid_argument se o tamanho ou formato for inválido.
    */
    bool validar(string endereco);
public:
    /**
    * @brief construtor da classe Endereco.
    * @param endreco string com o endereco inicial.
    * @throws invalid_argument se a validação falhar.
    */
    Endereco(string endereco);
    /**
    * @brief Retorna o endereco armazenado no objeto.
    * @return A string do endereco validado.
    */
    string getEndereco() const;
    /**
    * @brief Define e valida um novo endereco para o objeto.
    * @param endereco Contendo a nova string  se o endereco for válido.
    */
    void setEndereco(string endereco);
};

#endif // DOMINIOS_ENDERECO_HPP_INCLUDED
