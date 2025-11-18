/**
* @file controladora.gerente.cpp
* @brief Impelementação das funções que administram a entrada e saída de dados do subsistema gerente.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#include "controladora.gerente.hpp"
#include <iostream>
#include <limits>

using namespace std;

void opcoesGerente(){
    msGerente edicao;
    do{
        limparTela();
        cout << "\n================================" << endl;
        cout << "      OPCOES GERENTE         " << endl;
        cout << "================================" << endl;
        cout << "[1] Visualizar gerentes\n";
        cout << "[2] Editar gerente\n";
        cout << "[3] Excluir conta\n";
        cout << "[4] Sair\n";
        cout << "==================================" << endl;
        cout << "-> Escolha uma opcao: ";
        int opcao;
        if(cin >> opcao){
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            switch(opcao){
            case 1:
                try{
                    cout << "Gerentes" << endl;
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            case 2:
                try{
                   cout << "Editar dados" << endl;
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            case 3:
                try{
                   cout << "Excluir conta" << endl;
                }catch(const invalid_argument& e){
                    cerr << e.what() << endl;
                }
                break;
            case 4:
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
            esperar(2);
        }
    }while(true);
    //ler, editar e excluir - gerente n pode criar gerente
}

bool validarCriarGerente(){
    string nome, email, senha;
    int ramal;
    maGerente ma_gerente;
    msGerente novoGerente;

    do{
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

<<<<<<< Updated upstream
        if(ma_gerente.validarConta(nome, email, ramal, senha)){
=======
        //não esta entrando
        cout << "Antes" << endl;
        if(gerente.validarConta(nome, email, ramal, senha)){
>>>>>>> Stashed changes
            novoGerente.criarGerente(nome, email, ramal, senha);
            cout << "Conta criada com sucesso!\nRedirecionando..." << endl;
            esperar(2);
            return true;
        }else{
            cout << "\n==================================" << endl;
            cout << " Falha na validacao. Tente novamente." << endl;
            cout << "==================================" << endl;
            esperar(2);
        }

    }while(true);
    return false;
}

