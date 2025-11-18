/**
* @file iu.cpp
* @brief Implementacao do modulo principal de apresentacao (IU).
*
* Contem o loop de menu principal e a logica de limpeza de tela.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#include "iu.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <rpc.h>

using namespace std;

void telaGerente();

/**
* @brief Contem o menu principal que inicializa o sistema.
*/
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
                        opcoesGerente();
                    }
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                     esperar(10);
                }
                break;
            case 3:
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
    msGerente novoGerente;
    string novoDado, tipoDado;

    do{
        limparTela();

        cout << "\n================================" << endl;
        cout << " VOCE ESTA LOGADO COMO GERENTE " << endl;
        cout << "================================" << endl;
        cout << "[1] Abrir opcoes de Gerente\n"; //abrir a controladora de cada um
        cout << "[2] Abrir opcoes de Hoteis\n";
        cout << "[3] Abrir opcoes de Quartos\n";
        cout << "[4] Abrir opcoes de Reservas\n";
        cout << "[5] Abrir opcoes de Hospedes\n";
        cout << "[6] Sair\n";
        cout << "==================================" << endl;
        cout << "Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
                case 1:
                    opcoesGerente();
                    break;
                case 2:
                    cout << "Opcoes De Hoteis" << endl;
                    break;
                case 3:
                    cout << "Opcoes de Reservas" << endl;
                    break;
                case 4:
                    cout << "Opcoes de Reservas" << endl;
                    break;
                case 5:
                    cout << "Opcoes de Hospedes" << endl;
                    break;
                case 6:
                    cout << "Retornando ao menu inicial..." << endl;
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
