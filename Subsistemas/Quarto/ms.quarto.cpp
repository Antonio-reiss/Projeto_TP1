#include "ms.quarto.hpp"
using namespace std;

bool msQuarto::criarQuarto(Quarto& quarto, string& codigoHotel){
    bancoDeDados bd;

    if (bd.criarQuarto(quarto, codigoHotel)){
        esperar(3);
        return true;
    }
    return false;
}

void msQuarto::listarQuarto(){
    bancoDeDados bd;

    limparTela();
    cout << "\n================================" <<  endl;
    cout << "        LISTA DE QUARTO    " << endl;
    cout << "================================" <<  endl;
    bd.listarTodos("quarto");
    cout << "\n================================" <<  endl;
    string opcao;
    while(1){
        cout << "-> Digite 's' para sair: ";
        getline(cin, opcao);
        transform(opcao.begin(), opcao.end(), opcao.begin(),
                       [](unsigned char c){ return tolower(c); });

        if(opcao == "s"){
            return;
        }
    }
}

void msQuarto::listarQuartoFiltro(string& codigoHotel){
    bancoDeDados bd;

    limparTela();
    cout << "\n=================================" <<  endl;
    cout << "         LISTA  DE  QUARTOS    " << endl;
    cout << "=================================" <<  endl;
    cout << "Hotel:" << endl;
    bd.listarComFiltro("hotel", "codigo", codigoHotel);
    cout << endl;
    bd.listarComFiltro("quarto", "codigo_hotel", codigoHotel);
    cout << "\n================================" <<  endl;
    string opcao;
    while(1){
        cout << "-> Digite 's' para sair: ";
        getline(cin, opcao);
        transform(opcao.begin(), opcao.end(), opcao.begin(),
                       [](unsigned char c){ return tolower(c); });

        if(opcao == "s"){
            return;
        }
    }
}

bool msQuarto::updateQuarto(Quarto& quarto, int ID, bool edicao){
    bancoDeDados bd;

    if(!edicao){
        bd.montarQuarto(quarto, ID);
        return true;
    }

    bd.editarQuarto(quarto, ID);
    esperar(2);
    return true;
}

void msQuarto::apagarQuarto(int ID){
    bancoDeDados bd;

    bd.apagarUm("quarto", "id", to_string(ID));
    cout << "Hotel sendo excluido..." << endl;
    esperar(2);
    cout << "Hotel excluido com sucesso!" << endl;
    esperar(2);

    return;
}

void msQuarto::apagarQuartos(){
    bancoDeDados bd;

    bd.apagarTodos("quarto");
    cout << "Quartos sendo excluidos..." << endl;
    esperar(2);
    cout << "Quartos excluidos com sucesso!" << endl;
    esperar(2);

    return;
}
