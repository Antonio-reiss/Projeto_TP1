/**
* @file ms.gerente.cpp
* @brief implementacao concreta da logica de servico para o gerente.
*/
#include "ms.gerente.hpp"
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

//l

bool msGerente::editarGerente(const int& novoDado, const string& tipoDado, const string& email){
    Gerente edicaoGerente("Ellen", email, 04, "E5&0l");
    //Funcao(edicaoGerente) - passar p banco
        //retorna dados validos do gerente passado
    //cout informações a serem editadas
        //uso dos gets
    //do while com opcoes de editar dados e switch-case
        //já alterar e exibir na próxima edição
    //ao final salvar alterações -

}

bool msGerente::editarGerente(const string& novoDado, const string& tipoDado, const string& email){

}

bool msGerente::excluirGerente(const string& nome, const string& email, const int& ramal, const string& senha){

}
