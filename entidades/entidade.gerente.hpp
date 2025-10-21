#ifndef ENTIDADE_GERENTE_HPP_INCLUDED
#define ENTIDADE_GERENTE_HPP_INCLUDED

#include "entidade.pessoa.hpp"
#include  "../dominios/dominios.ramal.hpp"
#include "../dominios/dominios.senha.hpp"

using namespace std;

class Gerente : public Pessoa{
private:
    Ramal ramal;
    Senha senha;
public:
    Gerente(const string& nome, const string& email, const int& ramal, const string& senha);
    void setRamal(int&);
    void setSenha(string&);
    void setNome(string&);
    void setEmail(string&);

    int getRamal() const;
    //string getNome() const;
    //string getEmail() const ;
    string getSenha() const;
};



#endif // ENTIDADE_GERENTE_HPP_INCLUDED
