/**
 * @file ms.hospede.hpp
 * @brief Implementação concreta do módulo de serviço do Hóspede.
 * @author Ester Andrade Sousa - 242012109
 */


#ifndef MS_HOSPEDE_HPP_INCLUDED
#define MS_HOSPEDE_HPP_INCLUDED

#include "is.hospede.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include "../funcoes.de.controles.hpp"

#include "../../entidades/entidade.hospede.hpp"
#include "../../dominios/dominios.nome.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.endereco.hpp"
#include "../../dominios/dominios.cartao.hpp"

class msHospede : public isHospede {

private:
    bancoDeDados db;

public:
    bool criarHospede(const string&, const string&, const string&, const string&) override;
    bool listarHospedes() override;
    bool editarHospede(string, string, string) override;
    bool excluirHospede(const string&) override;

};

#endif // MS_HOSPEDE_HPP_INCLUDED
