/**
* @file ma.gerente.cpp
* @brief Implementacao dos metodos de validacao da camada de apresentacao.
*
* Contem a logica concreta que instancia os dominios (Nome, Email, Senha e Ramal) para forcar a validacao.
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

bool maGerente::validarEditar(const string& novoDado, const int& tipoDado){
    try{
        if(tipoDado == 1){
            Nome nomeValido(novoDado);
            return true;
        }
        else if(tipoDado == 2){
            Email emailValido(novoDado);
            cout << "Agora aqui\n";
            return true;
        }
        else if(tipoDado == 3){
            int ramalInt = stoi(novoDado);
            Ramal ramalValido(ramalInt);
            return true;
        }
        else if(tipoDado == 4){
            Senha senhaValida(novoDado);
            return true;
        }
    }catch(const exception& error){
        cout << "Erro: " << error.what() << endl;
        return false;
    }
}


