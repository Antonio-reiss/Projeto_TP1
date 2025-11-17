/**
* @file dominios.email.hpp
* @brief Definicao da classe Email, que representa e valida um endereco de email.
* * O dominio Email segue regras estritas de formato (parte local, @, dominio).
* e limites de caracteres para garantir a validade do endereco.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef DOMINIOS_EMAIL_HPP_INCLUDED
#define DOMINIOS_EMAIL_HPP_INCLUDED
#include <string>

using namespace std;

/**
* @class Email
* @brief Representa e valida um endereco de email.
*
* Garante que o endereco possua o formato (local@dominio) e obedeca
* os limites de tamanho e regras de uso de caracteres.
*/
class Email{
private:
    string email;
    /**
    * @brief Verifica se a string do email atende a todas as regras de formatacao.
    * @param email A string contendo o email a ser validado.
    * @throws invalid_argument se alguma regra de formatacao for violada.
    */
    void validarFormato(const string& email);
public:
    /**
    * @brief Construtor da classe Email.
    * @param email String com o email inicial.
    * @throws invalid_argument se a validacao falhar.
    */
    Email(const string& email);
    /**
    * @brief Retorna o endereco de email armazenado no objeto.
    * @return A string do email validado.
    */
    string getEmail()const;
    /**
    * @brief Define e valida um novo endereco de email para o objeto.
    * @param email A nova string do email a ser validada e atribuida.
    * @throws invalid_argument se o novo email for invalido.
    */
    void setEmail(const string& email);
};

#endif // DOMINIO_EMAIL_HPP_INCLUDED
