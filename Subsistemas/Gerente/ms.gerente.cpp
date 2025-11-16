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

bool msGerente::lerGerente(const string& nome, const string& email, const int& ramal, const string& senha){
    try{
        Gerente buscarGerente(nome, email, ramal, senha);
        cout << "\n================================" <<  endl;
        cout << " LISTA DE GERENTES " << endl;
        cout << "================================" <<  endl;
        return true;
    }catch(const invalid_argument& erro){
        throw;
    }
}

bool msGerente::editarGerente(const int& novoDado, const string& tipoDado){


}

bool msGerente::editarGerente(const string& novoDado, const string& tipoDado){

}

bool msGerente::excluirGerente(const string& nome, const string& email, const int& ramal, const string& senha){

}
