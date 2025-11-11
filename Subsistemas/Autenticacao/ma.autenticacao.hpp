#ifndef MA_AUTENTICACAO_HPP_INCLUDED
#define MA_AUTENTICACAO_HPP_INCLUDED
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "ia.autenticacao.hpp"
#include <string>

using namespace std;

class aAutenticacao : public IAutenticacao {
public:
    bool validarDados(string&, string&) override;
};


#endif // MA_AUTENTICACAO_HPP_INCLUDED
