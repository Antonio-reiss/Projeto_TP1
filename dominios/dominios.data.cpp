#include "dominio.data.hpp"
#include <stdexcept>
#include <vector>
#include <sstream>

using namespace std;

static bool ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool Data::validar(int d, string m, int a) const {
    if (d < 1 || d > 31) return false;
    if (a < 2000 || a > 2999) return false;

    vector<string> meses = {"JAN","FEV","MAR","ABR","MAI","JUN","JUL","AGO","SET","OUT","NOV","DEZ"};
    int diasNoMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    int mesIndex = -1;
    for (int i = 0; i < 12; i++) {
        if (m == meses[i]) {
            mesIndex = i;
            break;
        }
    }
    if (mesIndex == -1) return false;

    if (mesIndex == 1 && ehBissexto(a)) {
        return d <= 29;
    } else {
        return d <= diasNoMes[mesIndex];
    }
}

Data::Data(int d, string m, int a) {
    setValor(d, m, a);
}

void Data::setValor(int d, string m, int a) {
    if (!validar(d, m, a)) {
        throw invalid_argument("Data invalida.");
    }
    dia = d;
    mes = m;
    ano = a;
}

int Data::getDia() const { return dia; }
string Data::getMes() const { return mes; }
int Data::getAno() const { return ano; }

string Data::getValor() const {
    stringstream ss;
    ss << dia << "-" << mes << "-" << ano;
    return ss.str();
}

