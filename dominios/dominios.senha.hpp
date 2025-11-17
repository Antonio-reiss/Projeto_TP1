/**
* @file dominios.senha.hpp
* @brief Definicao da classe Senha, que representa e valida uma senha com regras rigidas.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef DOMINIOS_SENHA_HPP_INCLUDED
#define DOMINIOS_SENHA_HPP_INCLUDED
#include <string>

using namespace std;

/**
* @class Senha
* @brief Representa e valida uma senha com verificacoes estritas.
*
* @details Uma senha valida precisa cumprir os requisitos de ter 5 caracteres,
* letras (a-z ou A-Z), caracteres especiais (! " # $ % & ?),
* letras nao podem ser seguidas de letras, e nem digitos por digitos,
* e precisa conter pelo menos uma letra minuscula e maiuscula.
*/
class Senha{
private:
    string senha;
    static const int QTD_CARACTERES = 5;
    /**
    * @brief Verifica de a senha atende a todos os requisitos estabelecidos.
    * @param senha eh a string de senha a ser validada.
    * @return true se a senha for valida, caso contrario, lanca excecao.
    * @throws invalid_argument se qualquer regra (tamanho, tipo de caractere, sequencia) for violada.
    */
    bool validar_senha(string&);
public:
    /**
    * @brief Construtor da classe Senha.
    * @param senha eh a string de senha inicial.
    */
    Senha(string);
    /**
    * @brief Define e valida uma nova senha.
    * @param senha nova a ser validada.
    */
    void setSenha(string&);
    /**
    * @brief Retorna a senha armazena no objeto.
    * @return A string da senha.
    */
    string getSenha() const;
};


#endif // DOMINIOS_SENHA_HPP_INCLUDED
