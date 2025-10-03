#ifndef DOMINIOS_NOME_HPP_INCLUDED
#define DOMINIOS_NOME_HPP_INCLUDED

#include <string>

class Nome{
    private:
        std::string nome;
        void validar(std::string nome);
    public:
        Nome(std::string nome);
        std::string getNome() const;
        void setNome(std::string nome);
};

#endif // DOMINIOS_NOME_HPP_INCLUDED
