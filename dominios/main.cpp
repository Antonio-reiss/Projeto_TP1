#include "../Subsistemas/Autenticacao/ma.autenticacao.hpp"
#include <iostream>
#include <string>

bool validarDados(string&, string&);
using namespace std;

int main(){
    string email, senha;

inicio:
    cin >> email >> senha;

    aAutenticacao auth;
    bool validados = auth.validarDados(email, senha);

    if (!validados){
        goto inicio;
    }
    cout << "Deu certo" << endl;

    return 0;
 }
