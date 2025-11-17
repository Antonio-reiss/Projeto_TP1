/**
* @file ms.gerente.cpp
* @brief implementacao concreta da logica de servico para o gerente.
*/
#include "ms.gerente.hpp"
#include "ma.gerente.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

bool msGerente::criarGerente(const string& nome, const string& email, const int& ramal, const string& senha){
    try{
        Gerente gerente(nome, email, ramal, senha);
        cout << "Gerente criado com sucesso." << endl;
        return true;
    }catch(const invalid_argument& erro){
        throw;
    }
}

bool msGerente::listarGerentes(){ //listar todos os gerentes
    try{
        cout << "\n================================" <<  endl;
        cout << " LISTA DE GERENTES " << endl;
        cout << "================================" <<  endl;
        return true;
    }catch(const invalid_argument& erro){
        throw;
    }
}

bool msGerente::editarGerente(int novoDado, string tipoDado, string email){
    Gerente edicaoGerente("Ellen", email, 04, "E5&0l");
    maGerente validarEdicao;
    //Funcao(edicaoGerente) - passar p banco
        //retorna dados validos do gerente passado
    //cout informações a serem editadas
    do{
        limparTela();
        cout << "\n==================================" << endl;
        cout << "          Editar dados      " << endl;
        cout << "==================================" << endl;
        cout << "Nome: " << edicaoGerente.getNome() << endl;
        cout << "E-mail: " << edicaoGerente.getEmail() << endl;
        cout << "Ramal: " << edicaoGerente.getRamal() << endl;
        cout << "Senha: " << edicaoGerente.getSenha() << endl;
        cout << "==================================" << endl;
        cout << "- Nome\n";
        cout << "- E-mail\n";
        cout << "- Ramal\n";
        cout << "- Senha\n";
        cout << "- Sair\n";
        cout << "==================================" << endl;
        cout << "-> Digite uma opcao: ";
        cin >> tipoDado;

        try{
            if(tipoDado == "ramal"){
                    cout << "Digite o novo ramal: ";
                    if(std::cin >> novoDado){
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }else{
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                if(validarEdicao.validarEditar(novoDado, "ramal")){
                    edicaoGerente.setRamal(novoDado);
                    cout << "Ramal editado com sucesso." << endl;
                    esperar(2);
                    }
            }else{
                cout << "========================================" << endl;
                cout << "Opcao invalida! Digite uma opcao do menu." << endl;
                cout << "========================================" << endl;
                esperar(2);
                }
            }catch(const invalid_argument& erro){
                cout << "Erro: " << erro.what() << endl;
                esperar(3);
            }
            return false;
    }while(true);
        //uso dos gets
    //do while com opcoes de editar dados e switch-case
        //já alterar e exibir na próxima edição
    //ao final salvar alterações -
    return false;
}

bool msGerente::editarGerente(string novoDado, string tipoDado, string email){
    Gerente edicaoGerente("Ellen", email, 04, "E5&0l");
    maGerente validarEdicao;
    do{
        //limparTela();
        cout << "\n==================================" << endl;
        cout << "          Editar dados      " << endl;
        cout << "==================================" << endl;
        cout << "Nome: " << edicaoGerente.getNome() << endl;
        cout << "E-mail: " << edicaoGerente.getEmail() << endl;
        cout << "Ramal: " << edicaoGerente.getRamal() << endl;
        cout << "Senha: " << edicaoGerente.getSenha() << endl;
        cout << "==================================" << endl;
        cout << "- Nome\n";
        cout << "- E-mail\n";
        cout << "- Ramal\n";
        cout << "- Senha\n";
        cout << "- Sair\n";
        cout << "==================================" << endl;
        cout << "-> Digite o dado que deseja editar: ";
        getline(cin, tipoDado);

        try{
            if(tipoDado == "nome"){
                    cout << "Digite o novo nome: ";
                    cin >> novoDado;
                if(validarEdicao.validarEditar(novoDado, "nome")){
                    edicaoGerente.setNome(novoDado);
                    cout << "Nome editado com sucesso." << endl;
                    esperar(2);
                    }
            }
            else if(tipoDado == "email"){
                cout << "Digite o novo e-mail: ";
                cin >> novoDado;
                if(validarEdicao.validarEditar(novoDado, "email")){
                    edicaoGerente.setEmail(novoDado);
                    cout << "E-mail editado com sucesso." << endl;
                    esperar(2);
                }
            }
            else if(tipoDado == "senha"){
                cout << "Digite a nova senha: ";
                cin >> novoDado;
                if(validarEdicao.validarEditar(novoDado, "senha")){
                    edicaoGerente.setSenha(novoDado);
                    cout << "Senha editada com sucesso." << endl;
                    esperar(2);
                }
            }
            else if(tipoDado == "sair"){
                cout << "Deseja confirmar as alterações?" << endl;
            }else{
                cout << "========================================" << endl;
                cout << "Opcao invalida! Digite uma opcao do menu." << endl;
                cout << "========================================" << endl;
                esperar(2);
                }
            }catch(const invalid_argument& erro){
                cout << "Erro: " << erro.what() << endl;
                esperar(3);
            }
    }while(true);
    return false;
}

bool msGerente::excluirGerente(const string& nome, const string& email, const int& ramal, const string& senha){

}
