#include "../entidades/entidade.gerente.hpp"
#include "dominios.ramal.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    int ramal;
    string nome, email, senha;

    cout << "Digite seu nome" << endl;
    cin >> nome;

    cout << "Digite seu email" << endl;
    cin >> email;

    cout << "Digite o ramal" << endl;
    cin >> ramal;

    cout << "Digite uma senha" << endl;
    cin >> senha;

    Gerente gerente(nome, email, ramal, senha);

    cout << "Gerente:" << endl;
    cout << "Nome:" << endl;
    cout << gerente.getNome() << endl;
    cout << endl;
    cout << "Email:" << endl;
    cout << gerente.getEmail() << endl;
    cout << "Ramal:" << endl;
    cout << gerente.getRamal() << endl;
    cout << "Senha:" << endl;
    cout << gerente.getSenha() << endl;
    cout << endl;

    return 0;
}
