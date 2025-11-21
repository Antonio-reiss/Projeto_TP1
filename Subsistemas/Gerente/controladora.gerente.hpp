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
* @details Lida com o loop de coleta de dados e utiliza a camada de apresentacao para validar
* o formato antes de chamar a camada de servico para persistencia.
* @return Retorna true se os dados forem validos, e false caso nao sejam validos.
*/
bool validarCriarGerente();
/**
* @brief Exibe o menu de opcoes CRUD para a entidade Gerente e gerencia o fluxo de controle.
* @details Delega as tarefas de CRUD para as respectivas funcoes de validacao/execucao.
*/
void opcoesGerente();
/**
* @brief Gerencia o fluxo de coleta e validacao dos dados da criacao de um Gerente.
*/
void validarEditarGerente();
/**
* @brief Gerencia o fluxo de exclusao de um gerente.
* @details Coleta o e-mail (chave), valida o formato (MA) e solicita a confirmacao antes de chamar
* a camada de servico.
*/
void excluirGerente();

#endif // CONTROLADORA_GERENTE_HPP_INCLUDED
