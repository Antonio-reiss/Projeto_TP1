/**
* @file dominios.nome.hpp
* @brief Definição da classe Nome, que representa e valida o nome de uma pessoa.
*
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef DOMINIOS_NOME_HPP_INCLUDED
#define DOMINIOS_NOME_HPP_INCLUDED
#include <string>

using namespace std;

/**
* @class Nome
* @brief Representa e valida o nome de uma pessoa com 5 a 20 caracteres.
*
* O Nome pode ser composto apenas por letras e espaços que separe os nomes (nome composto ou sobre nome).
*/
class Nome{
    private:
        string nome;
        /**
        * @brief Verifica se a string do nome atende a todas as regras do domínio.
        * @param nome Em string contendo o nome a ser validado.
        * @throws invalid_argument se o tamanho ou formato for inválido.
        */
        void validar(string nome);
    public:
        /**
        * @brief Construtor da classe Nome.
        * @param nome String com o nome inicial.
        * @throws invalid_argument se a validação falhar.
        */
        Nome(string nome);
        /**
        * @brief Retorna o nome armazenado no objeto.
        * @return A string do nome validado.
        */
        string getNome() const;
        /**
        * @brief Define e valida um novo nome para o objeto.
        * @param nome A nova string do nome a ser validada e atribuída.
        * @throws invalid_argument se o nome for inválido.
        */
        void setNome(string nome);
};

#endif // DOMINIOS_NOME_HPP_INCLUDED
