#include "../Subsistemas/IU/iu.hpp"

using namespace std;

int main(){

    bancoDeDados bd;

    bd.apagarTabela("gerente");
    bd.apagarTabela("hospede");
    bd.apagarTabela("hotel");
    bd.apagarTabela("quarto");
    bd.apagarTabela("reserva");

    iniciarSistema();

    return 0;
}
