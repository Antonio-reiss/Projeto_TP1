/**
* @file dominios.email.hpp
* @brief Definição da classe Email, que representa e valida um endereço de email.
* * O domínio Email segue regras estritas de formato (parte local, @, domínio).
* e limites de caracteres para garantir a validade do endereço.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef DOMINIOS_EMAIL_HPP_INCLUDED
#define DOMINIOS_EMAIL_HPP_INCLUDED
#include <string>

using namespace std;

/**
* @class Email
* @brief Representa e valida um endereço de email.
*
* Garante que o endereço possua o formato (local@dominio) e obedeça
* os limites de tamanho e regras de uso de caracteres.
*/
class Email{
private:
    string email;
    /**
    * @brief Verifica se a string do email atende a todas as regras de formatação.
    * @param email A string contendo o email a ser validado.
    * @throws invalid_argument se alguma regra de formatação for violada.
    */
    void validarFormato(const string& email);
public:
    /**
    * @brief Construtor da classe Email.
    * @param email String com o email inicial.
    * @throws invalid_argument se a validação falhar.
    */
    Email(const string& email);
    /**
    * @brief Retorna o endereco de email armazenado no objeto.
    * @return A string do email validado.
    */
    string getEmail()const;
    /**
    * @brief Define e valida um novo endereço de email para o objeto.
    * @param email A nova string do email a ser validada e atribuída.
    * @throws invalid_argument se o novo email for inválido.
    */
    void setEmail(const string& email);
};

#endif // DOMINIO_EMAIL_HPP_INCLUDED
