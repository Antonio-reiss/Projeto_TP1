#include "../Subsistemas/IU/iu.hpp"
#include "../Subsistemas/BancoDados/bancoDeDados.hpp"
#include "../entidades/entidade.gerente.hpp"
#include "../entidades/entidade.reserva.hpp"
#include "../entidades/entidade.hospede.hpp"
#include "../entidades/entidade.quarto.hpp"
#include "../entidades/entidade.hotel.hpp"
#include <iostream>

using namespace std;

int main(){

    iniciarSistema();

   bancoDeDados bd;

   bd.listarTodos("gerente");

    return 0;
}
