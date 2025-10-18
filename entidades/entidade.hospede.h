#ifndef ENTIDADE_HOSPEDE_H_INCLUDED
#define ENTIDADE_HOSPEDE_H_INCLUDED

#include "entidade.pessoa.hpp"
#include "../dominios/dominios.endereco.hpp"
#include "../dominios/dominios.cartao.h"

class Hospede : public Pessoa{
private:
    Endereco endereco;
    Cartao cartao;
public:
    Hospede(const std::string& nome,
            const std::string& email,
            const std::string& endereco,
            const std::string& cartao);
    void setEndereco(const std::string& endereco);
    std::string getEndereco() const;

    void setCartao(const std::string& cartao);
    std::string getCartao() const;

};


#endif // ENTIDADE_HOSPEDE_H_INCLUDED
