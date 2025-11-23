#include "ms.hotel.hpp"
using namespace std;

bool msHotel::criarHotel(Hotel& hotel, string& responsavel){
    bancoDeDados bd;

    if (bd.criarHotel(hotel, responsavel)){
        esperar(3);
        return true;
    }
    return false;
}

void msHotel::listarHotel(){
    bancoDeDados bd;

    limparTela();
    cout << "\n================================" <<  endl;
    cout << "       LISTA DE HOTEIS    " << endl;
    cout << "================================" <<  endl;
    bd.listarTodos("hotel");
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

void msHotel::listarHotelFiltro(string& responsavel){
    bancoDeDados bd;

    bd.listarComFiltro("hotel", "responsavel", responsavel);
    return;
}

bool msHotel::updateHotel(Hotel& hotel, string& codigo){
    bancoDeDados bd;

    if (codigo == "0"){
        bd.montarHotel(hotel);
        return true;
    }

    bd.editarHotel(hotel, codigo);
    esperar(2);
    return true;
}

void msHotel::apagarHotel(string& codigo){
    bancoDeDados bd;

    bd.apagarUm("hotel", "codigo", codigo);
    cout << "Hotel sendo excluido..." << endl;
    esperar(2);
    cout << "Hotel excluido com sucesso!" << endl;
    esperar(2);

    return;
}

void msHotel::apagarHoteis(){
    bancoDeDados bd;

    bd.apagarTodos("hotel");
    cout << "Hoteis sendo excluidos..." << endl;
    esperar(2);
    cout << "Hoteis excluidos com sucesso!" << endl;
    esperar(2);

    return;
}
