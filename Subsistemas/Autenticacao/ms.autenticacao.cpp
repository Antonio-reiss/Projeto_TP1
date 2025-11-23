#include "ms.autenticacao.hpp"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>

string msAutenticacao::validarGerente(string& email, string& senha){
    bancoDeDados bd;

    string achou = bd.getSenha(email);

    if (achou == "404"){
        return "Usuario nao encontrado.";
    }

    if(achou == senha){
        return "Usuario validado!";
    }

    return "Senha incorreta!!";
}
