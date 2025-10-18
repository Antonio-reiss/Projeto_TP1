#include "entidade.reserva.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

// Pega os meses dados como de chegada e de saída para verificar se a chegada foi informada como data anterior à Data
// de partida, já que o contrário não teria sentido.
bool Reserva::validarDatas(Data &chegada, Data &partida)
{
    string meses[] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};
    int meschegada;
    int mespartida;

    for (int idx = 0; idx < 12; idx++)
    {
        if (chegada.getMes() == meses[idx])
        {
            meschegada = idx;
        }
        if (partida.getMes() == meses[idx])
        {
            mespartida = idx;
        }
    }
    if (chegada.getAno() > partida.getAno())
    {
        throw logic_error("A data de chegada nao pode ser posterior a de saida.");
    }
    else if (meschegada > mespartida)
    {
        throw logic_error("A data de chegada nao pode ser posterior a de saida.");
    }
    else if (chegada.getDia() > partida.getDia())
    {
        throw logic_error("A data de chegada nao pode ser posterior a de saida.");
    }
    return true;
}

//Exige a anexação de dados para a criação dos atributos, sendo estes, classes instanciadas.
//Reserva::Reserva(int& diaChegada, string& mesChegada, int& anoChegada, int& diaPartida, string& mesPartida, int& anoPartida, double& valorDinheiro):chegada(diaChegada, mesChegada, anoChegada), partida(diaPartida, mesPartida, anoPartida), valor(valorDinheiro){
//       validarDatas(this->chegada, this->partida);
//}

//Reserva::Reserva(Data chegada, Data partida, Dinheiro valor){
//    setReserva(chegada, partida, valor);
//}

void Reserva::setChegada(Data novaChegada)
{
    if (validarDatas(novaChegada, this->partida))
    {
        int dia = novaChegada.getDia();
        string mes = novaChegada.getMes();
        int ano = novaChegada.getAno();
        this->chegada.setValor(dia, mes, ano);
    }
    throw logic_error("A data de chegada deve anteceder a de partida.");
}

void Reserva::setPartida(Data novaPartida)
{
    if (validarDatas(this->chegada, novaPartida))
    {
        int dia = novaPartida.getDia();
        string mes = novaPartida.getMes();
        int ano = novaPartida.getAno();
        this->partida.setValor(dia, mes, ano);
    }
    throw logic_error("A data de chegada deve anteceder a de partida.");
}

void Reserva::setValorDinheiro(double preco)
{
    this->valor.setValor(preco);
}

void Reserva::setReserva(Data novaChegada, Data novaPartida, double novoValor)
{
    if (validarDatas(novaChegada, novaPartida))
    {
        setChegada(novaChegada);
        setPartida(novaPartida);
    }
    else
    {
        throw logic_error("O valor dia da chegada deve anteceder o dia da partida.");
    }

    setValorDinheiro(novoValor);
}

string Reserva::getChegada()
{
    return this->chegada.getValor();
}

string Reserva::getPartida()
{
    return this->partida.getValor();
}

double Reserva::getValor()
{
    return this->valor.getValor();
}
