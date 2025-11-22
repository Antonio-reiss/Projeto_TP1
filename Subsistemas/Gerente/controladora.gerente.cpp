/**
* @file controladora.gerente.cpp
* @brief Impelementacao das funcoes que administram a entrada e saida de dados do subsistema gerente.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#include "controladora.gerente.hpp"
#include <iostream>
#include <limits>

using namespace std;

void opcoesGerente();
void validarEditarGerente();
void excluirGerente();

void opcoesGerente(){
    msGerente servicoGerente;
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
                servicoGerente.listarGerentes();
                break;
            case 2:
                validarEditarGerente();
                break;
            case 3:
                excluirGerente();
                break;
            case 4:
                cout << "Saindo..." << endl;
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
        cin.clear();
        cin >> ramal;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Senha: ";
        getline(cin, senha);
        cout << endl << endl;

        if(ma_gerente.validarConta(nome, email, ramal, senha)){
            novoGerente.criarGerente(nome, email, ramal, senha);
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

void validarEditarGerente(){
    bancoDeDados bd;
    maGerente ca_gerente;
    msGerente cs_gerente;
    bd.listarTodos("gerente");
    string email;
    cout << "Digite o e-mail do gerente a ser editado: " << endl;
    getline(cin, email);
    Gerente edicaoGerente("nomee", email, 01, "1!a!A");

    do{
        limparTela();
        cout << "\n==================================" << endl;
        cout << "          Editar dados      " << endl;
        cout << "==================================" << endl;
        cout << "[1] Nome: " << edicaoGerente.getNome() << endl;
        cout << "[2] E-mail: " << edicaoGerente.getEmail() << endl;
        cout << "[3] Ramal: " << edicaoGerente.getRamal() << endl;
        cout << "[4] Senha: " << edicaoGerente.getSenha() << endl;
        cout << "[5] Salvar tudo e sair\n";
        cout << "==================================\n" << endl;
        cout << "-> Digite o numero do dado que deseja editar: ";
        int tipoDado;
        cin.clear();
        cin >> tipoDado;
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n==================================\n" << endl;
        string novoDado;
        maGerente validarEdicao;

        if(tipoDado == 1){
                cout << "Digite o novo nome: ";
                cin >> tipoDado;
            if(validarEdicao.validarEditar(novoDado, 1)){
                edicaoGerente.setNome(novoDado);
            }
        }
        else if(tipoDado == 2){
                cout << "Digite o novo e-mail: ";
                cin >> tipoDado;
            if(validarEdicao.validarEditar(novoDado, 2)){
                edicaoGerente.setEmail(novoDado);
            }
        }
        else if (tipoDado == 3){
            cout << "Digite o novo ramal: ";
            cin >> tipoDado;
            int ramalInt = stoi(novoDado);
            if(validarEdicao.validarEditar(novoDado, 3)){
                edicaoGerente.setRamal(ramalInt);
            }
        }
        else if(tipoDado == 4){
            cout << "Digite a nova senha: ";
            cin >> tipoDado;
            if(validarEdicao.validarEditar(novoDado, 4)){
                edicaoGerente.setSenha(novoDado);
            }
        }
        else if(tipoDado == 5){
            cs_gerente.editarGerente(tipoDado, novoDado, email);
            return;
        }

    }while(true);
}

void excluirGerente(){
    maGerente validarExcluir;
    msGerente servicoExcluir;

    do{
        limparTela();
        cout << "\n=====================================" << endl;
        cout << "       Excluir conta Gerente      " << endl;
        cout << "========================================" << endl;
        string email;
        cout << "Digite o e-mail da conta que deseja excluir:\n-> ";
        getline(cin, email);

        if(validarExcluir.validarEditar(email, 2)){
            cout << "\n==================================" << endl;
            cout << "ATENCAO: Esta acao eh irreversivel.\nConfirmar excluisao? [s/n]\n-> ";
            string confirmacao;
            getline(cin, confirmacao);
            std::transform(confirmacao.begin(), confirmacao.end(), confirmacao.begin(),
                       [](unsigned char c){ return std::tolower(c); });

            if(confirmacao == "s"){
                servicoExcluir.excluirGerente(email);
                return;
            }else if (confirmacao == "n"){
                cout << "Acao cancelada.\nVoltando ao menu Gerente.." << endl;
                esperar(3);
                return;
            }
        }else{
            cout << "E-mail invalido!" << endl;
        }

    }while(true);
}
