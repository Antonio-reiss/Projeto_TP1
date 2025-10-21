#include "dominios.ramal.hpp"
#include <stdexcept>
#include <math.h>

using namespace std;

bool Ramal::validar_ramal(float ramal){
    if (ramal < MIN_RAMAL || ramal > MAX_RAMAL){
        throw invalid_argument("O valor do ramal deve ser de 00 a 50");
    }
    if (floor(ramal) != ramal){
        throw invalid_argument("O ramal deve ser um valor inteiro");
    }
    return true;
}

void Ramal::setRamal(float ramal){
    validar_ramal(ramal);
    this->ramal = ramal;
}

Ramal::Ramal(float ramal){
    setRamal(ramal);
}

float Ramal::getRamal() const{
    return this->ramal;
}
