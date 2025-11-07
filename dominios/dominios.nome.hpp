#ifndef DOMINIOS_NOME_HPP_INCLUDED
#define DOMINIOS_NOME_HPP_INCLUDED
#include <string>

using namespace std;

class Nome{
    private:
        string nome;
        void validar(string nome);
    public:
        Nome(string nome);
        string getNome() const;
        void setNome(string nome);
};

#endif // DOMINIOS_NOME_HPP_INCLUDED
