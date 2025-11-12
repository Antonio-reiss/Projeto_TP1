/**
* @file entidade.quarto.hpp
* @brief Implementação dos métodos da entidade Quarto.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "entidade.quarto.hpp"

using namespace std;

Quarto::Quarto(const int& numero, const int& capacidade, const string& diaria, const int& ramal):
    numero(numero),
    capacidade(capacidade),
    diaria(diaria),
    ramal(ramal)
{};

void Quarto::setNumero(int numero){
    this->numero.setNumero(numero);
}

void Quarto::setCapacidade(int capacidade){
    this->capacidade.setValor(capacidade);
}

void Quarto::setDiaria(const string& diaria){
    this->diaria = Dinheiro(diaria);
}

void Quarto::setRamal(int ramal){
    this->ramal.setRamal(ramal);
}

int Quarto::getNumero() const{
    return this->numero.getNumero();
}

int Quarto::getCapacidade() const{
    return this->capacidade.getValor();
}

double Quarto::getDiaria() const{
    return this->diaria.getValor();
}

int Quarto::getRamal() const{
    return this->ramal.getRamal();
}
