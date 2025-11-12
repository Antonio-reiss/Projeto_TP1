#ifndef MS_AUTENTICACAO_HPP_INCLUDED
#define MS_AUTENTICACAO_HPP_INCLUDED
#include "../../entidades/entidade.gerente.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "is.autenticacao.hpp"

using namespace std;

class msAutenticacao : public isAutenticacao {
public:
    bool validarGerente(string&, string&) override;
};

#endif // MS_AUTENTICACAO_HPP_INCLUDED
