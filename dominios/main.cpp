#include "dominios.data.hpp"
#include <iostream>

using namespace std;

int main(){
    int dia, ano;
    string mes;

    cin >> dia;
    cin >> mes;
    cin >> ano;

    Data data(dia, mes, ano);

    cout << data.getValor() << endl;

    return 0;
}
