#include "../Subsistemas/BancoDados/bancoDeDados.hpp"

using namespace std;

int main(){
    bancoDeDados bd;
    int numero = 101, capacidade = 4, ramal = 22;
    string diaria = "120,00";
    string newDiaria = "100,00";

    bd.listarTodos("quarto");
    Quarto quarto(numero, capacidade, diaria, ramal);
    bd.montarQuarto(quarto, 1);
    quarto.setCapacidade(1);
    quarto.setDiaria(newDiaria);
    bd.editarQuarto(quarto, 1);
    bd.listarTodos("quarto");


    return 0;
}
