#ifndef IA_AUTENTICACAO_HPP_INCLUDED
#define IA_AUTENTICACAO_HPP_INCLUDED

using namespace std;

class iaAutenticacao {
public:
    virtual bool validarDados(string&, string&) = 0;
};

#endif // IA_AUTENTICACAO_HPP_INCLUDED
