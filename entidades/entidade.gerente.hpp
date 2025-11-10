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
    Gerente(string& nome, string& email, int& ramal, string& senha);
    void setRamal(int&);
    void setSenha(string&);
    void setNome(string&);
    void setEmail(string&);

    int getRamal() const;
    string getGerenteNome() const;
    string getGerenteEmail() const ;
    string getSenha() const;
};



#endif // ENTIDADE_GERENTE_HPP_INCLUDED
