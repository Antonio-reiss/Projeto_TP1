/**
* @file iu.cpp
* @brief Implementação do módulo principal de apresentação (IU).
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "iu.hpp"
#include "../Autenticacao/autenticar.hpp"
#include "../Gerente/controladora.gerente.hpp"
#include "../Gerente/ma.gerente.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

void esperar(int segundos){
    std::this_thread::sleep_for(std::chrono::milliseconds(segundos));
}

void iniciarSistema(){
    do{
        limparTela();
        cout << "\n==================================" << endl;
        cout << "  SISTEMA DE GESTAO DE HOTELARIA  " << endl;
        cout << "==================================" << endl;
        cout << "1. Login\n";
        cout << "2. Cadastrar nova conta\n";
        cout << "3. Sair\n";
        cout << "==================================" << endl;
        cout << "Escolha uma opcao: ";
        int opcao;

        if(cin >> opcao){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                validar();
                break;
            case 2:
                validarGerente();
                break;
            case 3:
                cout << "Saindo do sistema..." << endl;
                esperar(2000);
                return;
            default:
                cout << "Opcao invalida!" << endl;
                esperar(3000);
            }
        }else{
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cerr << "Opcao invalida! Digite um numero do menu." << endl;
            esperar(3000);
        }
    }while(true);
}
