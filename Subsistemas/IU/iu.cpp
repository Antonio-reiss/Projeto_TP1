/**
* @file iu.cpp
* @brief Implementacao do modulo principal de apresentacao (IU).
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#include "iu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <rpc.h>

using namespace std;

void iniciarSistema(){
    do{
        limparTela();
        cout << "\n==================================" << endl;
        cout << "  SISTEMA DE GESTAO DE HOTELARIA  " << endl;
        cout << "==================================" << endl;
        cout << "[1] Login\n";
        cout << "[2] Cadastrar nova conta\n";
        cout << "[3] Sair\n";
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;

        if(cin >> opcao){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                try{
                    if(validar()){
                        telaGerente();
                    }
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                    esperar(10);
                }
                break;
            case 2:
                try{
                    if(validarCriarGerente()){
                        telaGerente();
                    }
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                     esperar(10);
                }
                break;
            case 3:
                cout << "\n==================================" << endl;
                cout << "Saindo do sistema..." << endl;
                esperar(2);
                return;
            default:
                cout << "\n==================================" << endl;
                cout << "Opcao invalida!\nDigite um numero do menu." << endl;
                cout << "==================================" << endl;
                 esperar(6);
            }
        }else{
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "========================================" << endl;
            cerr << "Opcao invalida! Digite um numero do menu." << endl;
            cout << "========================================" << endl;
             esperar(6);
        }
    }while(true);
}

void telaGerente(){
    do{
        limparTela();

        cout << "\n================================" << endl;
        cout << " VOCE ESTA LOGADO COMO GERENTE " << endl;
        cout << "================================" << endl;
        cout << "[1] Abrir opcoes de Gerente\n"; //abrir a controladora de cada um
        cout << "[2] Abrir opcoes de Hospedes\n";
        cout << "[3] Abrir opcoes de Hoteis\n";
        cout << "[4] Abrir opcoes de Quartos\n";
        cout << "[5] Abrir opcoes de Reservas\n";
        cout << "[6] Sair\n";
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
                case 1:
                    opcoesGerente();
                    break;
                case 2:
                    //opcoesHospede();
                    break;
                case 3:
                    cout << "Opcoes de Hoteis" << endl;//chama a tela de opcoes de hoteis
                    break;
                case 4:
                    cout << "Opcoes de quartos" << endl;//chama a tela de opcoes de quartos
                    break;
                case 5:
                    //opcoesReserva();
                    break;
                case 6:
                    cout << "Retornando ao menu inicial..." << endl;
                    esperar(3);
                    return;
                default:
                cout << "\n==================================" << endl;
                cout << "Opcao invalida!\nDigite um numero do menu." << endl;
                cout << "==================================" << endl;
            }
        }else{
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "========================================" << endl;
            cerr << "Opcao invalida! Digite um numero do menu." << endl;
            cout << "========================================" << endl;
        }
    }while(true);

}

