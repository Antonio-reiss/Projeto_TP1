#include "controladora.hotel.hpp"
#include <iostream>
#include <limits>
#include <string>

void opcoesHotel(){
    while(1){
        limparTela();
        cout << "\n================================" << endl;
        cout << "         OPCOES GERENTE         " << endl;
        cout << "================================" << endl;
        cout << "[0] Criar hotel\n";
        cout << "[2] Visualizar hoteis\n";
        cout << "[3] Editar hotel\n";
        cout << "[4] Excluir hotel\n";
        cout << "[5] Sair\n";
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                validarCriarHotel();
                break;

            case 2:
                //mostrarHoteis();
                break;

            case 3:
                //editarHotel();
                break;

            case 4:
                //excluirHotel();
                break;

            case 5:
                cout << "Saindo do sistema..." << endl;
                esperar(2);
                return;
            default:
                cout << "\n\n\n==================================" << endl;
                cout << "Opcao invalida!\nDigite um numero do menu." << endl;
                cout << "==================================" << endl;
                esperar(2);
            }
        }

    }

}

void validarCriarHotel(){
    string nome, endereco, telefone, codigo;

    while(1){
        limparTela();

        cout << "================================" << endl;
        cout << "          Criar  Hotel          " << endl;
        cout << "================================" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Endereco: ";
        getline(cin, endereco);
        cout << "Telefone: ";
        getline(cin, telefone);
        cout << "Codigo: ";
        getline(cin, codigo);
        cout << endl << endl;




    }
}
