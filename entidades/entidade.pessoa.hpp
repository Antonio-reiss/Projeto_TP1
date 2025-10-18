#ifndef ENTIDADE_PESSOA_HPP_INCLUDED
#define ENTIDADE_PESSOA_HPP_INCLUDED

#include <string>
#include "../dominios/dominios.nome.hpp"
#include "../dominios/dominios.email.hpp"

class Pessoa{
private:
    Nome nome;
    Email email;
public:
    Pessoa(const std::string& nome, const std::string& email);
    void setNome(const std::string& nome);
    std::string getNome() const;
    void setEmail(const std::string& email);
    std::string getEmail() const;
};

#endif // ENTIDADE_PESSOA_HPP_INCLUDED
