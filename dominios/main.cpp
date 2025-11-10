#include "../entidades/entidade.gerente.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string senha, nome, email;
    int ramal;

    cin >> nome >> email >> senha;
    cin >> ramal;

    Gerente gerente(nome, email, ramal, senha);
    cout << gerente.getGerenteEmail() << endl << gerente.getGerenteNome();


    return 0;
}
