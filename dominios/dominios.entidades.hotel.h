#ifndef DOMINIOS_ENTIDADES_HOTEL_H_INCLUDED
#define DOMINIOS_ENTIDADES_HOTEL_H_INCLUDED

#include "dominios.codigo.hpp"
#include "dominios.nome.hpp"
#include "dominios.telefone.hpp"
#include "dominios.endereco.hpp"

class Hotel{
private:
    Nome nome;
    Endereco endereco;
    Telefone telefone;
    Codigo codigo;
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
