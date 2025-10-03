#include <iostream>
#include "dominios.senha.hpp"
#include <cstdlib>
using namespace std;

int main(){
    try{
        string senha;
        cout << "Defina uma senha." << endl;
        cout << "A senha deve conter: " << endl;
        cout << "Ao menos um caractere especial" << endl;
        cout << "Ao menos uma letra minuscula" << endl;
        cout << "Ao menos uma letra maiuscula" << endl;
        cout << "Ao menos um digito" << endl;
        cout << "Dois caracteres de mesmo tipo nao podem ser seguidos." << endl;
        cout << endl;

    cin >> senha;
    Senha password(senha);
    cout << endl;
    cout << "Senha = " << password.getSenha() << endl;
    }
    catch (invalid_argument){
    cout << "A senha inserida e invalida" << endl;
    cout << endl;
    system("cls");
    main();
    }

    return 0;
}

