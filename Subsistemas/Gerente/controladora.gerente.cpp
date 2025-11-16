/**
* @file controladora.gerente.cpp
* @brief Impelementação das funções que administram a entrada e saída de dados do subsistema gerente.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "controladora.gerente.hpp"
#include "../Autenticacao/autenticar.hpp"
#include "ma.gerente.hpp"
#include "ms.gerente.hpp"
#include "../IU/iu.hpp"
#include <iostream>
#include <limits>

using namespace std;

bool validarGerente(){
    string nome, email, senha;
    int ramal;
    maGerente gerente;

    limparTela();

    cout << "\n================================" << endl;
    cout << "      Criar conta Gerente         " << endl;
    cout << "================================" << endl;
    cout << "Nome: ";
    getline(cin, nome);
    cout << "E-mail: ";
    getline(cin, email);
    cout << "Ramal: ";
    cin >> ramal;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Senha: ";
    getline(cin, senha);
    cout << endl << endl;

    if(gerente.validarConta(nome, email, ramal, senha)){
        telaGerente();
        return true;
    }
    return false;
}

void telaGerente(){
    msGerente novoGerente;
    string novoDado, tipoDado;

    do{
        limparTela();

        cout << "\n================================" << endl;
        cout << " VOCE ESTA LOGADO COMO GERENTE " << endl;
        cout << "================================" << endl;
        cout << "1. Listar Gerentes\n";
        cout << "2. Listar Hoteis\n";
        cout << "3. Listar Quartos\n";
        cout << "4. Listar Reservas\n";
        cout << "5. Excluir Gerente\n";
        cout << "6. Editar Gerente\n";
        cout << "7. Sair\n";
        cout << "==================================" << endl;
        cout << "Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
                case 1:
                    cout << "\n================================" << endl;
                    cout << " GERENTES CADASTRADOS NO SISTEMA " << endl;
                    cout << "================================" << endl;
                    break;
                case 2:
                    cout << "\n================================" << endl;
                    cout << " HOTEIS CADASTRADOS NO SISTEMA " << endl;
                    cout << "================================" << endl;
                    break;
                case 3:
                    cout << "\n================================" << endl;
                    cout << " QUARTOS CADASTRADOS NO SISTEMA " << endl;
                    cout << "================================" << endl;
                    break;
                case 4:
                    cout << "\n================================" << endl;
                    cout << " RESERVAS CADASTRADAS NO SISTEMA " << endl;
                    cout << "================================" << endl;
                    break;
                case 5:
                    cout << "\n=====================" << endl;
                    cout << " EXCLUIR CONTA GERENTE " << endl;
                    cout << "=======================" << endl;
                    break;
                case 6:
                    cout << "\n=====================" << endl;
                    cout << " EDITAR CONTA GERENTE " << endl;
                    cout << "=======================" << endl;
                    cout << "Digite qual dado voce deseja alterar: ";
                    cin >> tipoDado;
                    cout << "Digite o novo " << tipoDado << ": ";
                    cin >> novoDado;
                    break;
                case 7:
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
