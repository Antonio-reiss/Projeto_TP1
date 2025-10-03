#ifndef DOMINIOS_NUMERO_HPP_INCLUDED
#define DOMINIOS_NUMERO_HPP_INCLUDED

class Numero{
private:
    int numero;
    static const int MAX_VALOR = 999;
    static const int MIN_VALOR = 1;
    bool validar_numero(int);
public:
    Numero(int);
    bool setNumero(int);
    int getNumero() const;
};

#endif // DOMINIOS_NUMERO_HPP_INCLUDED
