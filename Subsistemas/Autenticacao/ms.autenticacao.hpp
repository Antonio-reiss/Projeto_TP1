/**
* @file ms.autenticacao.hpp
* @brief Implementacao concreta da interface abstrata de autenticacao.
*
* @details Herda da interface de autenticacao, uma classe abstrata
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef MS_AUTENTICACAO_HPP_INCLUDED
#define MS_AUTENTICACAO_HPP_INCLUDED
#include "../../entidades/entidade.gerente.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "../../dominios/dominios.email.hpp"
#include "../BancoDados/bancoDeDados.hpp"
#include "is.autenticacao.hpp"

using namespace std;

/**
* @class msAutenticacao
* @brief Implementacao do modulo de servico para a autenticacao de gerentes.
* @details Contem a validacao dos dados no banco.
*/
class msAutenticacao : public isAutenticacao {
public:
    /**
    * @brief Cria
    * @details
    * @param
    * @return
    */
    string validarGerente(string&, string&) override;
};

#endif // MS_AUTENTICACAO_HPP_INCLUDED
