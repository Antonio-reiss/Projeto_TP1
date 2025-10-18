#include "dominios.data.hpp"
#include <stdexcept>
#include <sstream>

using namespace std;

static bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool Data::validar(int dia, string mes, int ano) const {
    if (dia < 1 || dia > 31) return false;
    if (ano < 2000 || ano > 2999) return false;

    string meses[] = {"JAN","FEV","MAR","ABR","MAI","JUN","JUL","AGO","SET","OUT","NOV","DEZ"};
    int diasNoMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int mesIndex = -1;
    for (int i = 0; i < 12; i++) {
        if (mes == meses[i]) {
            mesIndex = i;
            break;
        }
    }
    if (mesIndex == -1) return false;

    if (mesIndex == 1 && ehBissexto(ano)) {
        return dia <= 29;
    } else {
        return dia <= diasNoMes[mesIndex];
    }
}

Data::Data(int dia, string mes, int ano) {
    setValor(dia, mes, ano);
}

void Data::setValor(int dia, string mes, int ano) {
    if (!validar(dia, mes, ano)) {
        throw invalid_argument("Data invalida.");
    }
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

int Data::getDia() const { return dia; }
string Data::getMes() const { return mes; }
int Data::getAno() const { return ano; }

string Data::getValor() const {
    stringstream ss;
    ss << dia << "-" << mes << "-" << ano;
    return ss.str();
}


