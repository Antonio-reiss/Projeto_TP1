#include "ma.hospede.hpp"

using namespace std;

bool maHospede::validarHospede(const string& nome, const string& email, const string& endereco, const string& cartao){
    try{
        Nome nomeValido(nome);
        Email emailValido(email);
        Endereco enderecoValido(endereco);
        Cartao cartaoValido(cartao);
        return true;
    }catch(const exception& erro){
        cerr << "Dados invalidos!\nErro: " << erro.what() << endl;
        return false;
    }
}

bool maHospede::validarEditar(const string& novoDado, const string& tipoDado){
    if(tipoDado == "nome"){
        Nome nomeValido(novoDado);
    }
    else if(tipoDado == "email"){
        Email emailValido(novoDado);
    }
    else if(tipoDado == "endereco"){
        Endereco enderecoValido(novoDado);
    }
    else if(tipoDado == "cartao"){

    }
}
