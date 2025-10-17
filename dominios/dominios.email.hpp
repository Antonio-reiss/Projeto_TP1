#ifndef DOMINIOS_EMAIL_HPP_INCLUDED
#define DOMINIOS_EMAIL_HPP_INCLUDED
#include <string>
#include <stdexcept>

using namespace std;

class Email{
private:
    string endereco;
    bool validarFormato(const string& email);
public:
    Email(const string& endereco);
    string getEndereco()const;
    bool setEndereco(const string& endereco);
};

#endif // DOMINIO_EMAIL_HPP_INCLUDED
