#ifndef DOMINIOS_EMAIL_HPP_INCLUDED
#define DOMINIOS_EMAIL_HPP_INCLUDED
#include <string>

using namespace std;

class Email{
private:
    string email;
    bool validarFormato(const string& email);
public:
    Email(const string& email);
    string getEmail()const;
    void setEmail(const string& email);
};

#endif // DOMINIO_EMAIL_HPP_INCLUDED
