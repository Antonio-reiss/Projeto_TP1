#include "../Subsistemas/BancoDados/bancoDeDados.hpp"
#include "../entidades/entidade.gerente.hpp"
#include "../entidades/entidade.reserva.hpp"
#include "../entidades/entidade.hospede.hpp"
#include "../entidades/entidade.quarto.hpp"
#include "../entidades/entidade.hotel.hpp"
#include <iostream>

using namespace std;

int main(){
    bancoDeDados bd;
    Nome nome("Asas Douradas");
    Endereco endereco("Avenida 6 Bloco 16");
    Telefone telefone("5561995916016");
    Codigo codigo("asadourada");

    Reserva reserva(9, "FEV", 2005, 31, "MAR", 2005, 4550.00, "aaaaaaaaaa");
    bd.criarReserva(reserva, 1, "lucas@gmail.com");
    bd.listarTodos("reserva");


    return 0;
}
