/**
* @file controladora.gerente.hpp
* @brief Gerencia o subsistema de gerente.
* @author Maria Ellen Guedes Montalvão - 2232011402
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
* @brief Executa a coleta de dados e a validação para a criação da conta de gerente.
* @return Retorna true se os dados forem validos, false caso não sejam validos.
*/
bool validarCriarGerente();
void telaGerente();

#endif // CONTROLADORA_GERENTE_HPP_INCLUDED
