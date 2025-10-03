#ifndef DOMINIOS_EMAIL_HPP_INCLUDED
#define DOMINIOS_EMAIL_HPP_INCLUDED

#include <string>
#include <stdexcept>

class Email{
private:
    std::string endereco; //endereco de e-mail
    bool validarFormato(const std::string& email);
public:
    Email(const std::string& endereco);
    std::string getEndereco()const;
    bool setEndereco(const std::string& endereco);
};

#endif // DOMINIO_EMAIL_HPP_INCLUDED
