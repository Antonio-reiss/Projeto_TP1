#ifndef DOMINIOS_SENHA_HPP_INCLUDED
#define DOMINIOS_SENHA_HPP_INCLUDED
#include <string>

using namespace std;

class Senha{
private:
    string senha;
    static const int QTD_CARACTERES = 5;
    bool validar_senha(string&);
public:
    Senha(string);
    void setSenha(string&);
    string getSenha() const;
};


#endif // DOMINIOS_SENHA_HPP_INCLUDED
