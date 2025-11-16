/**
* @file iu.cpp
* @brief Implementacao do modulo principal de apresentacao (IU).
*
* Contem o loop de menu principal e a logica de limpeza de tela.
* @author Maria Ellen Guedes Montalvao - 232011402
*/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "iu.hpp"
#include "../Autenticacao/autenticar.hpp"
#include "../Gerente/controladora.gerente.hpp"
#include "../Gerente/ma.gerente.hpp"
#include <iostream>
#include <string>
#include <cstdlib>


#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <rpc.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

/**
* @brief Pausa a execução do programa pelo número de segundos especificado.
* @param segundos O tempo de pausa em segundos.
*/
void esperar(int segundos) {
    #ifdef _WIN32
        Sleep(segundos*1000);
    #else
        Sleep(segundos);
    #endif
}

/**
* @brief Contem o menu principal que inicializa o sistema.
*/
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
                try{
                    validar();
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            case 2:
                try{
                    validarGerente();
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
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
                esperar(2);
            }
        }else{
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "========================================" << endl;
            cerr << "Opcao invalida! Digite um numero do menu." << endl;
            cout << "========================================" << endl;
            esperar(2);
        }
    }while(true);
}
