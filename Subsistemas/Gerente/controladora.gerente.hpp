/**
* @file controladora.gerente.hpp
* @brief Gerencia o subsistema de gerente.
* @author Maria Ellen Guedes Montalvao - 2232011402
*/
#ifndef CONTROLADORA_GERENTE_HPP_INCLUDED
#define CONTROLADORA_GERENTE_HPP_INCLUDED
#include "../Autenticacao/autenticar.hpp"
#include "ma.gerente.hpp"
#include "ms.gerente.hpp"
#include "../IU/iu.hpp"
#include "../funcoes.de.controles.hpp"
#include <iostream>
#include <limits>

/**
* @brief Executa a coleta de dados e a validacao para a criacao da conta de Gerente.
* @details Esta funcao lida com a coleta de dados e validacao.
* @return Retorna true se os dados forem validos, e false caso nao sejam validos.
*/
bool validarCriarGerente();
/**
* @brief Exibe o menu principal para o Gerente logado.
* @details Eh chamada apos um login/cadastro bem-sucedido. Contem o loop principal para as entidades.
*/
void telaGerente();
/**
* @brief Exibe as opcoes de CRUD para a entidade Gerente e gerencia o fluxo de controle do mesmo.
*/
void opcoesGerente();

#endif // CONTROLADORA_GERENTE_HPP_INCLUDED
