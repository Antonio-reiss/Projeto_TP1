#include "../Subsistemas/Gerente/ma.gerente.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main(){
    string nomeValido, emailValido, senhaValida;
    float ramalValido = 02;

    cout << "-------- Criar conta - GERENTE --------" << endl;
    cout << "Nome: ";
    getline(cin, nomeValido);
    cout << "E-mail: ";
    getline(cin, emailValido);
    cout << "Senha: ";
    getline(cin, senhaValida);
    cout << "Ramal: ";
    cin >> ramalValido;

    maGerente servico;

    try{
        servico.validarConta(nomeValido, emailValido, ramalValido, senhaValida);
    }catch(const exception& e){
        cout << "Erro: " << e.what() << endl;
    }

    return 0;
}
