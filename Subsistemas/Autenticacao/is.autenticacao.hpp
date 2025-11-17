#ifndef IS_AUTENTICACAO_HPP_INCLUDED
#define IS_AUTENTICACAO_HPP_INCLUDED

using namespace std;

class isAutenticacao {
public:
    virtual string validarGerente(string&, string&) = 0;
};

#endif // IS_AUTENTICACAO_HPP_INCLUDED
