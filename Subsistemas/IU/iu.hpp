/**
* @file iu.hpp
* @brief Definicao da interface do modulo principal de apresentacao (IU).
*
* Esse modulo lida com o menu principal e o controle de fluxo do sistema.
* @author Maria Ellen Guedes Montalvao - 232011402
*/
#ifndef IU_HPP_INCLUDED
#define IU_HPP_INCLUDED
#include "../Autenticacao/autenticar.hpp"
#include "../HospedeReserva/controladora.hospede.hpp"
#include "../HospedeReserva/controladora.reserva.hpp"
#include "../Gerente/controladora.gerente.hpp"
#include "../Gerente/ma.gerente.hpp"
#include "../funcoes.de.controles.hpp"

/**
* @brief Contem o loop do menu principal que inicializa o sistema.
* @details Responsavel por receber a opcao do usuario e delegar o fluxo.
*/
void iniciarSistema();
/**
* @brief Exibe o menu principal de navegacao para o Gerente logado.
* @details Lida com o controle de fluxo para acessar as opcoes de CRUD de todas as entidades.
*/
void telaGerente();



#endif // IU_HPP_INCLUDED
