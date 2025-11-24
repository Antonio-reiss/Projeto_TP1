/**
* @file ia.autenticacao.hpp
* @brief Interface abstrata para camada de apresentacao do modulo autenticacao.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef IA_AUTENTICACAO_HPP_INCLUDED
#define IA_AUTENTICACAO_HPP_INCLUDED

using namespace std;

/**
* @class iaAutenticacao
* @brief Abstracao para o modulo de apresentacao de autenticacao.
*
* Esta interface define os metodos que devem ser implementados no modulo de autenticacao.
*/
class iaAutenticacao {
public:

    /**
    * @brief Faz a validacao de dados, verificando se seguem as regras de negocio.
    * @details Usa os construtores de dominio (Nome e Senha) para verificar.
    * @param referencia de string para o nome e para o email.
    * @return Retorna true se os dados seguirem o exigido.
    */
    virtual bool validarDados(string&, string&) = 0;
};

#endif // IA_AUTENTICACAO_HPP_INCLUDED
