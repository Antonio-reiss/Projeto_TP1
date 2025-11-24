/**
* @file is.autenticacao.hpp
* @brief Interface Abstrata para o modulo de servico de autenticacao.
*/
#ifndef IS_AUTENTICACAO_HPP_INCLUDED
#define IS_AUTENTICACAO_HPP_INCLUDED

using namespace std;

/**
* @class isAutenticacao
* @brief classe abstrata que define a funcao do modulo de servico de autenticacao.
*/
class isAutenticacao {
public:
    /**
    * @brief Busca os dados inseridos no Banco para ver se estao certos.
    * @details Busca no banco os dados solicitados e os compara para autenticacao.
    * @param duas referencias de string para email e senha.
    * @return Retorna uma string com a situacao, se o usuario existe, se foi validado, etc.
    */
    virtual string validarGerente(string&, string&) = 0;
};

#endif // IS_AUTENTICACAO_HPP_INCLUDED
