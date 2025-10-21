#ifndef DOMINIOS_RAMAL_HPP_INCLUDED
#define DOMINIOS_RAMAL_HPP_INCLUDED

class Ramal{
private:
    float ramal;
    static const int MAX_RAMAL = 50;
    static const int MIN_RAMAL = 0;
    bool validar_ramal(float);
public:
    Ramal(float);
    void setRamal(float);
    float getRamal() const;

};

#endif // DOMINIOS_RAMAL_HPP_INCLUDED
