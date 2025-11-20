/**
* @file entidade.gerente.hpp
* @brief Definicao da Entidade Gerente.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef ENTIDADE_GERENTE_HPP_INCLUDED
#define ENTIDADE_GERENTE_HPP_INCLUDED

#include "entidade.pessoa.hpp"
#include  "../dominios/dominios.ramal.hpp"
#include "../dominios/dominios.senha.hpp"

using namespace std;

/**
* @class Gerente
* @brief Representa um Gerente do sistema, responsavel por gerenciar outras entidades.
*/
class Gerente : public Pessoa{
private:
    Ramal ramal;
    Senha senha;
public:
    /**
    * @brief COnstrutor da classe Gerente.
    * @param nome Nome do Gerente (validado pelo dominio Nome, herdado de Pessoa).
    * @param email Email do Gerente (validado pelo dominio Email, herdado de Pessoa).
    * @param ramal Ramal do Gerente (validado pelo dominio Ramal, herdado de Pessoa).
    * @param senha Senha do Gerente (validado pelo dominio Senha, herdado de Pessoa).
    */
    Gerente(const string& nome, const string& email, const int& ramal, const string& senha);
    /**
    * @brief Define o valor do ramal, validando-o atrasves da classe Ramal.
    * @param Novo valor para o ramal.
    */
    void setRamal(int&);
    /**
    * @brief Define a nova senha, validando-a atraves da classe Senha.
    * @param senhaNova eh a nova senha.
    */
    void setSenha(string&);
    /**
    * @brief Define o novo nome, validando-o atraves da classe Nome.
    * @param nomeNovo eh o novo nome.
    */
    void setNome(string&);
    /**
    * @brief Define o novo email, validando-o atraves da classe Email.
    * @param emailNovo eh o novo email.
    */
    void setEmail(string&);

    /**
    * @brief Retorna o valor do ramal.
    * @return ramal inteiro.
    */
    int getRamal() const;
    /**
    * @brief Retorna o nome do Gerente.
    * @return nome como string.
    */
    string getGerenteNome() const;
    /**
    * @brief Retorna o email do Gerente.
    * @return email como string.
    */
    string getGerenteEmail() const;
    /**
    * @brief Retorna a senha do Gerente.
    * @return senha como string.
    */
    string getSenha() const;
};



#endif // ENTIDADE_GERENTE_HPP_INCLUDED
