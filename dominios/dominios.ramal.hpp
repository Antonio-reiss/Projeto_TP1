#ifndef DOMINIOS_RAMAL_HPP_INCLUDED
#define DOMINIOS_RAMAL_HPP_INCLUDED

class Ramal{
private:
    int ramal;
    static const int MAX_RAMAL = 50;
    static const int MIN_RAMAL = 0;
    bool validar_ramal(int);
public:
    Ramal(int);
    void setRamal(int);
    int getRamal() const;

};

#endif // DOMINIOS_RAMAL_HPP_INCLUDED
