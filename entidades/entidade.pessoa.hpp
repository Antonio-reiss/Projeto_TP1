/**
* @file entidade.pessoa.hpp
* @brief Definicao da Entidade Pessoa.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef ENTIDADE_PESSOA_HPP_INCLUDED
#define ENTIDADE_PESSOA_HPP_INCLUDED

#include <string>
#include "../dominios/dominios.nome.hpp"
#include "../dominios/dominios.email.hpp"

using namespace std;

/**
* @class Pessoa
* @brief Entidade base que representa uma pessoa no sistema.
*
* Contém objetos do tipo Nome e Email, valida e armazena os dados de uma pessoa.
*/
class Pessoa{
private:
    Nome nome;
    Email email;
public:
    /**
     * @brief Construtor da classe Pessoa.
     * @param nome String com o nome inicial a ser validado pelo Dominio Nome.
     * @param email String com o email inicial a ser validado pelo Dominio Email (PK).
     * @throws invalid_argument se a validacao de Nome ou Email falhar.
     */
    Pessoa(const string& nome, const string& email);
    /**
     * @brief Define e valida um novo nome para o objeto, delegando a validacao ao dominio Nome.
     * @param nome A nova string do nome a ser validada.
     */
    void setNome(const string& nome);
    /**
     * @brief Retorna a string do nome.
     * @return A string do nome validado.
     */
    string getNome() const;
    /**
    * @brief Define e valida um novo email para o objeto, delegando a validacao ao dominio Email.
    * @param A string do email a ser validado.
    */
    void setEmail(const string& email);
    /**
    * @brief Retorna a string do email.
    * @return A string do email valido.
    */
    string getEmail() const;
};

#endif // ENTIDADE_PESSOA_HPP_INCLUDED
