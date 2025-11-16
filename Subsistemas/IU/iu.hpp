/**
* @file iu.hpp
* @brief Definicao da interface do modulo principal de apresentacao (IU).
*
* Esse modulo lida com o menu principal e o controle de fluxo do sistema.
* @author Maria Ellen Guedes Montalvão - 232011402
*/
#ifndef IU_HPP_INCLUDED
#define IU_HPP_INCLUDED
#include "../Autenticacao/autenticar.hpp"
#include "../Gerente/controladora.gerente.hpp"
#include "../Gerente/ma.gerente.hpp"
#include "../funcoes.de.controles.hpp"


/**
* @brief Contém o menu que inicializa o sistema.
* * Responsavel por receber a opcao do usuario e delegar o fluxo.
*/
void iniciarSistema();

#endif // IU_HPP_INCLUDED
