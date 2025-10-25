#include "../entidades/entidade.pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string email, nome;

    cin >> nome;
    cin >> email;

    Pessoa alguem(nome, email);

    cout << alguem.getEmail() << endl << alguem.getNome();

    return 0;
}
