#ifndef BANCODEDADOS_HPP_INCLUDED
#define BANCODEDADOS_HPP_INCLUDED

#include "../../entidades/entidade.gerente.hpp"
#include "../../entidades/entidade.hospede.hpp"
#include "../../entidades/entidade.reserva.hpp"
#include "../../entidades/entidade.quarto.hpp"
#include "../../entidades/entidade.hotel.hpp"

#include "../../zSQL/sqlite3.h"
//#include <sqlite3.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class bancoDeDados {

private:
    sqlite3* bancoDados;
public:
    bancoDeDados();
    ~bancoDeDados();

    bool executar(const string&);

    bool criarGerente(Gerente&);
    bool criarHospede(Hospede&);
    bool criarReserva(Reserva&, int);
    bool criarQuarto(Quarto&, string&);
    bool criarHotel(Hotel&);


    void listarTodos(const string&);
    void listarComFiltro(const string&, const string&, const string&);


    void montarGerente(Gerente&);
    void montarHospede(Hospede&);
    void montarReserva(Reserva&);
    void montarQuarto(Quarto&, int);
    void montarHotel(Hotel&);
    void editarGerente(Gerente&);
    void editarHospede(Hospede&);
    void editarReserva(Reserva&);
    void editarQuarto(Quarto&);
    void editarHotel(Hotel&);


    bool apagarUm(const string&, const string&, const string&);
    bool apagarTodos(const string&);


    static int pegarValor(void* NaoUsado, int qtdCol, char** valor, char** nomeCol);
    static int mostrar(void* NaoUsado, int qtdCol, char** valor, char** nomeCol);
    static int pegarLinha(void* dado, int qtdCol, char** valor, char** nomeCol);

};

#endif // BANCODEDADOS_HPP_INCLUDED
