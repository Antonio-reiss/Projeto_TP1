/**
* @file controladora.autenticacao.hpp
* @brief Gerencia a autenticacao do gerente
* @author Antonio Lucas Paulo Reis Rodrigues dos Santos - 242010015
*/
#ifndef CONTROLADORA_AUTENTICACAO_HPP_INCLUDED
#define CONTROLADORA_AUTENTICACAO_HPP_INCLUDED
#include "ma.autenticacao.hpp"
#include "ms.autenticacao.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/**
* @brief Faz a coleta de dados para entrada na conta e comunica com os modulos de apresentacao e servico.
* @details Pega os dados recebidos e envia para o modulo de apresentacao para validar o tipo deles,
depois de validados, envia para a camada de servico para comparar com os dados do banco.
* @return Retorna true se os dados enviados forem os corretos e false, caso contrario.
*/
bool validar();


#endif // CONTROLADORA_AUTENTICACAO_HPP_INCLUDED
