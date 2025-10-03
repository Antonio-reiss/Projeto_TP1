#include "dominios.ramal.hpp"
#include <stdexcept>

using namespace std;

bool Ramal::validar_ramal(int ramal){
    if (ramal < MIN_RAMAL || ramal > MAX_RAMAL){
        throw invalid_argument("O ramal deve ser de 00 a 50");
    }
    return true;
}

bool Ramal::setRamal(int ramal){
    validar_ramal(ramal);
    this->ramal = ramal;
    return true;
}

Ramal::Ramal(int ramal){
    setRamal(ramal);
}

int Ramal::getRamal() const{
    return this->ramal;
}
