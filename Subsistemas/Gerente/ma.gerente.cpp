/**
* @file ma.gerente.cpp
* @brief Implementação dos métodos de validacao da camada de apresentacao.
*
* Contém a logica concreta que instancia os dominios (Nome, Email, Senha, ramal) para forçar a validacao.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#include "ma.gerente.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

bool maGerente::validarConta(const string& nome, const string& email, const int& ramal, const string& senha){
    try{
        Nome nomeValido(nome);
        Email emailValido(email);
        Ramal ramalValido(ramal);
        Senha senhaValida(senha);
        return true;
    }catch(const exception& erro){
        cerr << "Dados invalidos!\nErro: " << erro.what() << endl;
        return false;
    }

}

bool maGerente::validarEditar(const string& novoDado, const string& tipoDado){
    try{
        if(tipoDado == "nome"){
            Nome nomeValido(novoDado);
        }
        else if(tipoDado == "email"){
            Email emailValido(novoDado);
        }
        else if(tipoDado == "senha"){
            Senha senhaValida(novoDado);
        }
    }catch(const exception& error){
        cout << error.what() << endl;
        return false;
    }
    return true;
}

bool maGerente::validarEditar(const int& novoDado, const string& tipoDado){
    try{
        if(tipoDado == "ramal"){
            Ramal ramalValido(novoDado);
        }
    }catch(const exception& error){
        cout << error.what() << endl;
        return false;
    }
    return true;
}

