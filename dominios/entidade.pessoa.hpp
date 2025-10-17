#ifndef ENTIDADE_PESSOA_HPP_INCLUDED
#define ENTIDADE_PESSOA_HPP_INCLUDED
#include <string>
#include "dominios.nome.hpp"
#include "dominios.email.hpp"

using namespace std;

class Pessoa{
private:
    Nome nome;
    Email email;
public:
    Pessoa(const string& nome, const string& email);
    void setNome(const string& nome);
    string getNome() const;
    void setEmail(const string& email);
    string getEmail() const;
};

#endif // ENTIDADE_PESSOA_HPP_INCLUDED
