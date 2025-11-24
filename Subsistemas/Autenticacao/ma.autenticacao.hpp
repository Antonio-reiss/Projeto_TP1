/**
* @file ma.autenticacao.hpp
* @brief Definicao dos metodos virtuais criados na interface.
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef MA_AUTENTICACAO_HPP_INCLUDED
#define MA_AUTENTICACAO_HPP_INCLUDED
#include "../../dominios/dominios.email.hpp"
#include "../../dominios/dominios.senha.hpp"
#include "ia.autenticacao.hpp"
#include <string>

using namespace std;

/**
* @class maAutenticacao
* @brief Classe concreta que valida os dados de entrada nas regras de negocio do sistema.
*
* @details Esta classe usa heranca de uma classe abstrata e solidifica seus metodos.
*/
class maAutenticacao : public iaAutenticacao {
public:
    /**
    * @brief Valida, usando os dominios, se os valores inseridos sao validos
    * @param Referencias de strings para email e senha.
    * @return Retorna true se os dados seguem o esperado e false, caso contratio.
    */
    bool validarDados(string&, string&) override;
};


#endif // MA_AUTENTICACAO_HPP_INCLUDED
