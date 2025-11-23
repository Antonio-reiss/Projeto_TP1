#ifndef MS_QUARTO_HPP_INCLUDED
#define MS_QUARTO_HPP_INCLUDED
#include "is.quarto.hpp"

class msQuarto : public isQuarto{
public:
    bool criarQuarto(Quarto&, string&) override;
    void listarQuarto() override;
    void listarQuartoFiltro(string&) override;
    bool updateQuarto(Quarto&, int, bool) override;
    void apagarQuarto(int) override;
    void apagarQuartos() override;
};

#endif // MS_QUARTO_HPP_INCLUDED
