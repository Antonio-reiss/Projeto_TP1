#ifndef ENTIDADES_HOTEL_HPP_INCLUDED
#define ENTIDADES_HOTEL_HPP_INCLUDED

#include <vector>
#include "entidade.quarto.hpp"
#include "../dominios/dominios.codigo.hpp"
#include "../dominios/dominios.nome.hpp"
#include "../dominios/dominios.telefone.hpp"
#include "../dominios/dominios.endereco.hpp"

class Hotel{
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;
    vector<Quarto> quartos;
public:
    Hotel(Nome nome, Endereco endereco, Telefone telefone, Codigo codigo);
    void setNome(const Nome& nome);
    void setEndereco(const Endereco& endereco);
    void setTelefone(const Telefone& telefone);
    void setCodigo(const Codigo& codigo);

    Nome getNome() const;
    Endereco getEndereco() const;
    Telefone getTelefone() const;
    Codigo getCodigo() const;
};


#endif // DOMINIOS_ENTIDADES_HOTEL_H_INCLUDED
